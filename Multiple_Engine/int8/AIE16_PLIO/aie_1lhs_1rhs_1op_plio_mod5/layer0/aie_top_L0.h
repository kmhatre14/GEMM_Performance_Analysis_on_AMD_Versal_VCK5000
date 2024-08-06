#include "aie_graph_L0.h"

using namespace adf;

const int L0_A=2;
const int L0_B=4;
const int L0_C=2;
const int L0_A_BRO=4;
const int L0_C_BRO=4;

const int L0_NUM_INSTANCES=L0_A*L0_C;
const int L0_NUM_PACK_OUT=L0_NUM_INSTANCES/2;

class mm_x2_x4_x2_graph0 : public adf::graph {
public:
    input_port in_lhs[1][1];
    input_port in_rhs[1][1];
    adf::pktmerge<4>  mg_out[1];
	output_port out[1];

    adf::pktsplit<16> sp_a0_top;
    adf::pktsplit<16> sp_b0_top;

    mm_k7_B4_L0 <21, 0>  mm_0_0;
    mm_k7_B4_L0 <24, 1>  mm_0_1;
    mm_k7_B4_L0 <25, 0>  mm_1_0;
    mm_k7_B4_L0 <28, 1>  mm_1_1;

    mm_x2_x4_x2_graph0 () {
        mg_out[0] = adf::pktmerge<4>::create();
        sp_a0_top  = adf::pktsplit<16>::create();
        sp_b0_top  = adf::pktsplit<16>::create();
        adf::connect< adf::pktstream > (in_lhs[0][0], sp_a0_top.in[0]);
        adf::connect< adf::pktstream > (in_rhs[0][0], sp_b0_top.in[0]);
        
        for (int i=0; i<4; i++)  {
            connect<pktstream,pktstream>(sp_a0_top.out[i],mm_0_0.in0[i]);
            connect<pktstream,pktstream>(sp_a0_top.out[i+4],mm_0_1.in0[i]);
            connect<pktstream,pktstream>(sp_a0_top.out[i+8],mm_1_0.in0[i]);
            connect<pktstream,pktstream>(sp_a0_top.out[i+12],mm_1_1.in0[i]);

            connect<pktstream,pktstream>(sp_b0_top.out[i],mm_0_0.in1[i]);
            connect<pktstream,pktstream>(sp_b0_top.out[i+4],mm_0_1.in1[i]);
            connect<pktstream,pktstream>(sp_b0_top.out[i+8],mm_1_0.in1[i]);
            connect<pktstream,pktstream>(sp_b0_top.out[i+12],mm_1_1.in1[i]);
        }
        
        connect<window<L0_h1*L0_w2*L0_Byte>,pktstream>(mm_0_0.out,mg_out[0].in[0]);
        connect<window<L0_h1*L0_w2*L0_Byte>,pktstream>(mm_0_1.out,mg_out[0].in[1]);
        connect<window<L0_h1*L0_w2*L0_Byte>,pktstream>(mm_1_0.out,mg_out[0].in[2]);
        connect<window<L0_h1*L0_w2*L0_Byte>,pktstream>(mm_1_1.out,mg_out[0].in[3]);
        
        for (int i=0; i<1; i++)  {
            adf::connect<adf::pktstream> (mg_out[i].out[0], out[i]);
        }
    }
};