#include <adf.h>
#include <aie_api/aie.hpp>
#include "para_L0.h"
#include <aie_api/utils.hpp>

//For element mmul
const int M=4;
const int K=16;
const int N=8;

const int num_rowA=L0_h1/M;
const int num_colA=L0_w1/K;
const int num_colB=L0_w2/N;

void mm7_kernel0_L0(input_window_int8* __restrict matA, 
        input_window_int8*  __restrict matB,
        output_window_int8* __restrict matC){
    using MMUL = aie::mmul<M, K, N, int8, int8>;
    const int8* __restrict pA=(int8*)matA->ptr;
    const int8* __restrict pB=(int8*)matB->ptr;
    int8* __restrict pC=(int8*)matC->ptr;
    for(unsigned int i=0;i<num_rowA;i++) 
    chess_prepare_for_pipelining
	chess_loop_range(num_rowA,)
    {
        for (unsigned int j=0;j<num_colB;j++) 
        chess_prepare_for_pipelining
        chess_loop_range(num_colB,)
        {
            const int8* __restrict pA1=pA+(i*num_colA+0)*MMUL::size_A;
            const int8* __restrict pB1=pB+(0*num_colB+j)*MMUL::size_B;
            
            aie::vector<int8,MMUL::size_A> A0=aie::load_v<MMUL::size_A>(pA1); pA1+=MMUL::size_A;
            aie::vector<int8,MMUL::size_B> B0=aie::load_v<MMUL::size_B>(pB1); pB1+=MMUL::size_B*num_colB;

            MMUL C00;
            C00.mul(A0,B0);

            for (unsigned int k=0;k<num_colA-1;k++)
            chess_prepare_for_pipelining
            chess_loop_range(num_colA-1,)
            {
                A0=aie::load_v<MMUL::size_A>(pA1); pA1+=MMUL::size_A;
                B0=aie::load_v<MMUL::size_B>(pB1); pB1+=MMUL::size_B*num_colB;
                C00.mac(A0,B0);
            }

            aie::store_v(pC, C00.to_vector<int8>()); pC+=MMUL::size_C;
        }
    }
}