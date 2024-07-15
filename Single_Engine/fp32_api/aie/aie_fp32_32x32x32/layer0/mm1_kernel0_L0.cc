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
    for(unsigned int i=0;i<16;i++) // Generate matrix C by calculating tiles row-by-row
    //chess_prepare_for_pipelining
	//chess_loop_range(16,)
    {
        for (unsigned int j=0;j<8;j++) // Fill in a row of tiles in C by the end of this loop
        chess_prepare_for_pipelining
        chess_loop_range(8,)
        {
            // Generate a tile of A
            aie::vector<float,4> va1=window_read_v<4>(matA); 
            aie::vector<float,MMUL::size_A> va;
            va.insert(0,va1); // Insert the first row to the tile
            window_incr_v32(matA,1); // Go to the next row
            aie::vector<float,4> va2=window_read_v<4>(matA);
            va.insert(1,va2); // Insert the second row to the tile
            // Generate a tile of B
            aie::vector<float,MMUL::size_B> vb;
            for (unsigned int a=0;a<4;a++) 
            //chess_unroll_loop(*)
            {
                aie::vector<float, 4> rvb=window_read_v<4>(matB); // Get a row of data for a tile of B
                window_incr_v32(matB,1); // Go to next row
                vb.insert(a,rvb);
            }
            MMUL mvc; mvc.mul(va,vb); // Calling mul initializes the tile
            window_decr(matA,28); // Move window A backwards to the first position in the next tile

            for (unsigned int k=0;k<7;k++) // Matrix multiply by each corresponding tiles from A and B
            chess_prepare_for_pipelining
            chess_loop_range(7,)
            {
                // Generate a tile of A
                va1=window_read_v<4>(matA); 
                va.insert(0,va1); // Insert the first row to the tile
                window_incr_v32(matA,1); // Go to the next row
                va2=window_read_v<4>(matA);
                va.insert(1,va2); // Insert the second row to the tile
                // Generate a tile of B
                for (unsigned int a=0;a<4;a++) 
                //chess_unroll_loop(*)
                {
                    aie::vector<float, 4> rvb=window_read_v<4>(matB); // Get a row of data for a tile of B
                    window_incr_v32(matB,1); // Go to next row
                    vb.insert(a,rvb);
                }
                mvc.mac(va,vb);
                window_decr(matA,28); // Move window A backwards to the first position in the next tile
            }

            // Store the results into C's tile
            auto vc=mvc.to_vector<float>(MMUL::size_C);
            window_write(matC,vc.extract<4>(0));
            window_incr_v32(matC,1);
            window_write(matC,vc.extract<4>(1));

            // Move window C's position back to the tile's highest row but advance to the next tile 
            window_decr(matC,28);

            // Advance the position for window B to correspond to the next tile for C
            window_decr_v32(matB,32);
            window_incr(matB,4);
            
            // Move window A's position back to the start
            window_decr_v32(matA,1);
        }
        // Advance window A's and C's positions to the a new row for generating a row of tiles 
        window_incr_v32(matA,2);
        window_incr_v32(matC,1);
    }
}
