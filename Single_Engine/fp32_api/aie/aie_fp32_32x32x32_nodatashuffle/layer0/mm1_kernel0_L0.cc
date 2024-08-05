#include <adf.h>
#include <aie_api/aie.hpp>
#include "para_L0.h"
#include <aie_api/utils.hpp>

//For element mmul
const int M=2;
const int K=4;
const int N=4;

const int num_rowA=L0_h1/M;
const int num_colA=L0_w1/K;
const int num_colB=L0_w2/N;

void mm1_kernel0_L0(input_window_float* __restrict matA, 
        input_window_float* __restrict matB,
        output_window_float* __restrict matC){
    using MMUL = aie::mmul<M, K, N, float, float>;
    const float* __restrict pA=(float*)matA->ptr;
    const float* __restrict pB=(float*)matB->ptr;
    float* __restrict pC=(float*)matC->ptr;
    for(unsigned int i=0;i<num_rowA;i++) 
    chess_prepare_for_pipelining
	chess_loop_range(num_rowA,)
    {
        for (unsigned int j=0;j<num_colB;j++) 
        chess_prepare_for_pipelining
        chess_loop_range(num_colB,)
        {
            const float* __restrict pA1=pA+(i*num_colA+0)*MMUL::size_A;
            const float* __restrict pB1=pB+(0*num_colB+j)*MMUL::size_B;
            
            aie::vector<float,MMUL::size_A> A0=aie::load_v<MMUL::size_A>(pA1); pA1+=MMUL::size_A;
            aie::vector<float,MMUL::size_B> B0=aie::load_v<MMUL::size_B>(pB1); pB1+=MMUL::size_B*num_colB;

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

            aie::store_v(pC, C00.to_vector<float>()); pC+=MMUL::size_C;
        }
    }
}
