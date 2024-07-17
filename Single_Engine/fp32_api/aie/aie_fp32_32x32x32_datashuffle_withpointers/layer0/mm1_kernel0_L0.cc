#include <adf.h>
#include <aie_api/aie.hpp>
#include "para_L0.h"
#include <aie_api/utils.hpp>

//For element mmul
const int M=2;
const int K=4;
const int N=4;

void mm1_kernel0_L0(input_window_float* __restrict matA, 
        input_window_float* __restrict matB,
        output_window_float* __restrict matC){
    using MMUL = aie::mmul<M, K, N, float, float>;
    const float* __restrict pA= (float*)matA->ptr;
    const float* __restrict pB= (float*)matB->ptr;
    float* __restrict pC= (float*)matC->ptr;

    for(unsigned int i=0;i<L0_w1;i+=M) // Generate matrix C by calculating tiles row-by-row
    {        
        const float* __restrict pA_[M];
        float* __restrict pC_[M];
        for (unsigned int j=0;j<M;j++)
        //chess_unroll_loop(*)
        {
            pA_[j] = pA + (i+j)*L0_w1;
            pC_[j] = pC + (i+j)*L0_w2;
        }
        for (unsigned int j=0;j<L0_w2/N;j++) // Fill in a row of tiles in C by the end of this loop
        chess_prepare_for_pipelining
        chess_loop_range(L0_w2/N,)
        {
            const float* __restrict pB1 = pB + j*N;

            // Generate a tile of A
            aie::vector<float,MMUL::size_A> va;
            for (unsigned int k=0;k<M;k++)
            //chess_unroll_loop(*)
            {
                aie::vector<float,K> rva=aie::load_v<K>(pA_[k]); pA_[k]+=K;
                va.insert(k,rva);
            }
            // Generate a tile of B
            aie::vector<float,MMUL::size_B> vb;
            for (unsigned int k=0;k<K;k++) 
            //chess_unroll_loop(*)
            {
                aie::vector<float, N> rvb=aie::load_v<N>(pB1); pB1+=L0_w2; 
                vb.insert(k,rvb);
            }
            MMUL mvc; mvc.mul(va,vb); // Calling mul initializes the tile

            for (unsigned int k=0;k<L0_w1/K-1;k++) // Matrix multiply by each corresponding tiles from A and B
            chess_prepare_for_pipelining
            chess_loop_range(L0_w1/K-1,)
            {
                // Generate a tile of A
                for (unsigned int a=0;a<M;a++)
                //chess_unroll_loop(*)
                {
                    aie::vector<float,K> rva=aie::load_v<K>(pA_[a]); pA_[a]+=K;
                    va.insert(a,rva); // Insert the first row to the tile
                }
                // Generate a tile of B
                for (unsigned int a=0;a<K;a++) 
                //chess_unroll_loop(*)
                {
                    aie::vector<float, N> rvb=aie::load_v<N>(pB1); pB1+=L0_w2; 
                    vb.insert(a,rvb);
                }
                mvc.mac(va,vb);
            }

            // Store the results into C's tile
            for (unsigned int k=0;k<M;k++)
            //chess_unroll_loop(*)
            {
                auto vc=mvc.to_vector<float>();
                aie::store_v(pC_[k],vc.extract<N>(k)); pC_[k] += N;
                pA_[k]-=L0_w1;
            }
        }
    }
}
