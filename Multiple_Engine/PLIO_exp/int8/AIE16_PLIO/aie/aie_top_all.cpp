#include "layer0/aie_top_L0.h"
using namespace adf;

PLIO* LHS_in0_L0 = new PLIO("LHS_in0_L0", adf::plio_128_bits, "data/input0.txt",230);
PLIO* LHS_in1_L0 = new PLIO("LHS_in1_L0", adf::plio_128_bits, "data/input0.txt",230);
PLIO* LHS_in2_L0 = new PLIO("LHS_in2_L0", adf::plio_128_bits, "data/input0.txt",230);
PLIO* LHS_in3_L0 = new PLIO("LHS_in3_L0", adf::plio_128_bits, "data/input0.txt",230);
PLIO* LHS_in4_L0 = new PLIO("LHS_in4_L0", adf::plio_128_bits, "data/input0.txt",230);
PLIO* LHS_in5_L0 = new PLIO("LHS_in5_L0", adf::plio_128_bits, "data/input0.txt",230);
PLIO* LHS_in6_L0 = new PLIO("LHS_in6_L0", adf::plio_128_bits, "data/input0.txt",230);
PLIO* LHS_in7_L0 = new PLIO("LHS_in7_L0", adf::plio_128_bits, "data/input0.txt",230);

PLIO* RHS_in0_L0 = new PLIO("RHS_in0_L0", adf::plio_128_bits, "data/input1.txt",230);
PLIO* RHS_in1_L0 = new PLIO("RHS_in1_L0", adf::plio_128_bits, "data/input1.txt",230);
PLIO* RHS_in2_L0 = new PLIO("RHS_in2_L0", adf::plio_128_bits, "data/input1.txt",230);
PLIO* RHS_in3_L0 = new PLIO("RHS_in3_L0", adf::plio_128_bits, "data/input1.txt",230);
PLIO* out0_L0 = new PLIO("out0_L0", adf::plio_128_bits, "data/output0.txt",230);
PLIO* out1_L0 = new PLIO("out1_L0", adf::plio_128_bits, "data/output1.txt",230);

simulation::platform<12, 2> platform(
LHS_in0_L0,
LHS_in1_L0,
LHS_in2_L0,
LHS_in3_L0,
LHS_in4_L0,
LHS_in5_L0,
LHS_in6_L0,
LHS_in7_L0,
RHS_in0_L0, 
RHS_in1_L0, 
RHS_in2_L0, 
RHS_in3_L0, 
out0_L0,
out1_L0 
);


mm_x2_x4_x2_graph0  mm_graph0;


connect<> net_lhs_in0_L0 (platform.src[0], mm_graph0.in_lhs[0][0]);
connect<> net_lhs_in1_L0 (platform.src[1], mm_graph0.in_lhs[0][1]);
connect<> net_lhs_in2_L0 (platform.src[2], mm_graph0.in_lhs[1][0]);
connect<> net_lhs_in3_L0 (platform.src[3], mm_graph0.in_lhs[1][1]);
connect<> net_lhs_in4_L0 (platform.src[4], mm_graph0.in_lhs[2][0]);
connect<> net_lhs_in5_L0 (platform.src[5], mm_graph0.in_lhs[2][1]);
connect<> net_lhs_in6_L0 (platform.src[6], mm_graph0.in_lhs[3][0]);
connect<> net_lhs_in7_L0 (platform.src[7], mm_graph0.in_lhs[3][1]);

connect<> net_rhs_in0_L0 (platform.src[8], mm_graph0.in_rhs[0][0]);
connect<> net_rhs_in1_L0 (platform.src[9], mm_graph0.in_rhs[0][1]);
connect<> net_rhs_in2_L0 (platform.src[10], mm_graph0.in_rhs[1][0]);
connect<> net_rhs_in3_L0 (platform.src[11], mm_graph0.in_rhs[1][1]);
connect<> net_out0_L0 (mm_graph0.out[0], platform.sink[0]);
connect<> net_out1_L0 (mm_graph0.out[1], platform.sink[1]);
#ifdef __AIESIM__
int main(int argc, char** argv) {
    mm_graph0.init();
    mm_graph0.run(4);
    mm_graph0.end();
    return 0;
}
#endif