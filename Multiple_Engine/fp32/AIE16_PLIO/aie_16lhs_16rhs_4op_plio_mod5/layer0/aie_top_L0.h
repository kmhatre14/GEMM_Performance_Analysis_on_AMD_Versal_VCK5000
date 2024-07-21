#include "aie_graph_L0.h"

using namespace adf;

const int L0_A=1;
const int L0_B=4;
const int L0_C=4;
const int L0_A_BRO=4;
const int L0_C_BRO=4;

const int L0_NUM_INSTANCES=L0_A*L0_C;
const int L0_NUM_PACK_OUT=L0_NUM_INSTANCES/4;

class mm_x1_x4_x4_graph0 : public adf::graph {
public:
    input_port in_lhs[16];
    input_port in_rhs[16];
    adf::pktmerge<4>  mg_out[L0_NUM_PACK_OUT];
	output_port out[4];

    
    mm_k1_B4_L0 <23, 0>  mm_0_0;
    mm_k1_B4_L0 <26, 1>  mm_0_2;
    mm_k1_B4_L0 <23, 2>  mm_0_1;
    mm_k1_B4_L0 <26, 3>  mm_0_3;


    mm_x1_x4_x4_graph0 () {
        // for (int i =0; i<L0_NUM_PACK_OUT; i++)  {
        //     mg_out[i] = adf::pktmerge<4>::create();
        // }

        
        // sp_b0_top  = adf::pktsplit<16>::create();
        // adf::connect< adf::pktstream > (in_rhs[0][0], sp_b0_top.in[0]);
        for (int i=0; i<4; i++)  {
            connect<pktstream,window<L0_h1*L0_w1*L0_Byte>>(in_lhs[i],mm_0_0.in0[i]);
            connect<pktstream,window<L0_h1*L0_w1*L0_Byte>>(in_lhs[i+4],mm_0_1.in0[i]);
            connect<pktstream,window<L0_h1*L0_w1*L0_Byte>>(in_lhs[i+8],mm_0_2.in0[i]);
            connect<pktstream,window<L0_h1*L0_w1*L0_Byte>>(in_lhs[i+12],mm_0_3.in0[i]);
        
            connect<pktstream,window<L0_h1*L0_w1*L0_Byte>>(in_rhs[i],mm_0_0.in1[i]);
            connect<pktstream,window<L0_h1*L0_w1*L0_Byte>>(in_rhs[i+4],mm_0_1.in1[i]);
            connect<pktstream,window<L0_h1*L0_w1*L0_Byte>>(in_rhs[i+8],mm_0_2.in1[i]);
            connect<pktstream,window<L0_h1*L0_w1*L0_Byte>>(in_rhs[i+12],mm_0_3.in1[i]);
        }
        
        // connect<pktstream,pktstream>(sp_b0_top.out[0],mm_0_0.in1[0]);
        // connect<pktstream,pktstream>(sp_b0_top.out[1],mm_0_1.in1[1]);
        // connect<pktstream,pktstream>(sp_b0_top.out[2],mm_0_2.in1[2]);
        // connect<pktstream,pktstream>(sp_b0_top.out[3],mm_0_3.in1[3]);
        

        connect<window<L0_h1*L0_w2*L0_Byte>,pktstream>(mm_0_0.out,out[0]);
        connect<window<L0_h1*L0_w2*L0_Byte>,pktstream>(mm_0_1.out,out[1]);
        connect<window<L0_h1*L0_w2*L0_Byte>,pktstream>(mm_0_2.out,out[2]);
        connect<window<L0_h1*L0_w2*L0_Byte>,pktstream>(mm_0_3.out,out[3]);
        

        // for (int i=0; i<L0_NUM_PACK_OUT; i++)  {
        //     adf::connect<adf::pktstream> (mg_out[i].out[0], out[i]);
        // }
    }
};