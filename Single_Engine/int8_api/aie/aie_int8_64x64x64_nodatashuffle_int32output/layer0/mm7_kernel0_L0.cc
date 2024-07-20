#include <adf.h>
#include <aie_api/aie.hpp>
#include "para_L0.h"
#include <aie_api/utils.hpp>

//For element mmul
const int M=4;
const int K=8;
const int N=4;

const int num_rowA=L0_h1/M;
const int num_colA=L0_w1/K;
const int num_colB=L0_w2/N;
const int SHIFT = 10;

void mm7_kernel0_L0(input_window_int8* __restrict matA, 
        input_window_int8*  __restrict matB,
        output_window_int32* __restrict matC){
    using MMUL = aie::mmul<M, K, N, int8, int8>;
    const int8* __restrict pA=(int8*)matA->ptr;
    const int8* __restrict pB=(int8*)matB->ptr;
    int32* __restrict pC=(int32*)matC->ptr;
    for(unsigned int i=0;i<num_rowA;i+=2) 
    chess_prepare_for_pipelining
    // chess_loop_range(num_rowA/2,)
    // chess_flatten_loop
    {
        int32* __restrict pC1 = pC + (i * num_rowA) * MMUL::size_C;
        int32* __restrict pC2 = pC + ((i+1) * num_rowA) * MMUL::size_C;
        for (unsigned int j=0;j<num_colB;j+=2) 
        chess_prepare_for_pipelining
        // chess_loop_range(num_colB/2,)
        // chess_flatten_loop
        {
            const int8 * __restrict pA1 = pA + ( i * num_colA + 0) * MMUL::size_A;
            const int8 * __restrict pA2 = pA + ( (i+1) * num_colA + 0) * MMUL::size_A;

            const int8 * __restrict pB1 = pB + ( 0 * num_colB + j) * MMUL::size_B;
            const int8 * __restrict pB2 = pB + ( 0 * num_colB + (j+1)) * MMUL::size_B;
            
            aie::vector<int8, MMUL::size_A> A0 = aie::load_v<MMUL::size_A>(pA1); pA1 += MMUL::size_A;
            aie::vector<int8, MMUL::size_A> A1 = aie::load_v<MMUL::size_A>(pA2); pA2 += MMUL::size_A;

            aie::vector<int8, MMUL::size_B> B0 = aie::load_v<MMUL::size_B>(pB1); pB1 += MMUL::size_B * num_colB;
            aie::vector<int8, MMUL::size_B> B1 = aie::load_v<MMUL::size_B>(pB2); pB2 += MMUL::size_B * num_colB;

            MMUL C00;
            MMUL C01;
            MMUL C10;
            MMUL C11;

            // matrix multiply by initializing to 0
            C00.mul(A0, B0);
            C01.mul(A0, B1);
            C10.mul(A1, B0);
            C11.mul(A1, B1);

            for (unsigned int k=0;k<num_colA-1;k++)
            chess_prepare_for_pipelining
            // chess_loop_range(num_colA-1,)
            // chess_flatten_loop
            {
                A0 = aie::load_v<MMUL::size_A>(pA1); pA1 += MMUL::size_A;
                A1 = aie::load_v<MMUL::size_A>(pA2); pA2 += MMUL::size_A;

                B0 = aie::load_v<MMUL::size_B>(pB1); pB1 += MMUL::size_B * num_colB;
                B1 = aie::load_v<MMUL::size_B>(pB2); pB2 += MMUL::size_B * num_colB;

                // matrix multiply and adding partial blocks
                C00.mac(A0, B0);
                C01.mac(A0, B1);
                C10.mac(A1, B0);
                C11.mac(A1, B1);
            }

            aie::store_v(pC1, C00.template to_vector<int32>(/*SHIFT*/)); pC1 +=MMUL::size_C;
            aie::store_v(pC1, C01.template to_vector<int32>(/*SHIFT*/)); pC1 +=MMUL::size_C;
            aie::store_v(pC2, C10.template to_vector<int32>(/*SHIFT*/)); pC2 +=MMUL::size_C;
            aie::store_v(pC2, C11.template to_vector<int32>(/*SHIFT*/)); pC2 +=MMUL::size_C;
        }
    }
}