#include "layer0/aie_top_L0.h"
using namespace adf;

PLIO* LHS_in0_L0 = new PLIO("LHS_in0_L0", adf::plio_128_bits, "data/input0.txt",230);
// PLIO* LHS_in1_L0 = new PLIO("LHS_in1_L0", adf::plio_128_bits, "data/input0.txt",230);

PLIO* RHS_in0_L0 = new PLIO("RHS_in0_L0", adf::plio_128_bits, "data/input1.txt",230);
// PLIO* RHS_in1_L0 = new PLIO("RHS_in1_L0", adf::plio_128_bits, "data/input1.txt",230);
// PLIO* RHS_in2_L0 = new PLIO("RHS_in2_L0", adf::plio_128_bits, "data/input1.txt",230);
// PLIO* RHS_in3_L0 = new PLIO("RHS_in3_L0", adf::plio_128_bits, "data/input1.txt",230);
PLIO* out0_L0 = new PLIO("out0_L0", adf::plio_128_bits, "data/output0.txt",230);

simulation::platform<2, 1> platform(
    LHS_in0_L0,
    RHS_in0_L0, 
    out0_L0 
);

// simulation::platform<6, 1> platform(
// LHS_in0_L0,
// LHS_in1_L0,
// RHS_in0_L0, 
// RHS_in1_L0, 
// RHS_in2_L0, 
// RHS_in3_L0, 
// out0_L0 
// );

mm_x1_x4_x4_graph0  mm_graph0;


connect<> net_lhs_in0_L0 (platform.src[0], mm_graph0.in_lhs[0]);
// connect<> net_lhs_in1_L0 (platform.src[1], mm_graph0.in_lhs[1][0]);

connect<> net_rhs_in0_L0 (platform.src[1], mm_graph0.in_rhs[0]);
// connect<> net_rhs_in1_L0 (platform.src[3], mm_graph0.in_rhs[1][0]);
// connect<> net_rhs_in2_L0 (platform.src[4], mm_graph0.in_rhs[2][0]);
// connect<> net_rhs_in3_L0 (platform.src[5], mm_graph0.in_rhs[3][0]);
connect<> net_out0_L0 (mm_graph0.out[0], platform.sink[0]);
//#ifdef __AIESIM__
int main(int argc, char** argv) {
    std::cout << "Modifying the simulation env to simulate just one 32x32x32 MatA * MatB computation.!!";
    mm_graph0.init();
    mm_graph0.run(1);
    mm_graph0.end();
    return 0;
}
//#endif