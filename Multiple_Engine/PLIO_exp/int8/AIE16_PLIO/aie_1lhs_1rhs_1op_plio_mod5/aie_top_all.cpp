#include "layer0/aie_top_L0.h"
using namespace adf;

PLIO* LHS_in0_L0 = new PLIO("LHS_in0_L0", adf::plio_128_bits, "data/3plio/input0.txt",230);
PLIO* RHS_in0_L0 = new PLIO("RHS_in0_L0", adf::plio_128_bits, "data/3plio/input1.txt",230);
PLIO* out0_L0 = new PLIO("out0_L0", adf::plio_128_bits, "data/output0.txt",230);

simulation::platform<2, 1> platform(
LHS_in0_L0,
RHS_in0_L0, 
out0_L0
);

mm_x2_x4_x2_graph0  mm_graph0;

connect<> net_lhs_in0_L0 (platform.src[0], mm_graph0.in_lhs[0][0]);
connect<> net_rhs_in0_L0 (platform.src[1], mm_graph0.in_rhs[0][0]);
connect<> net_out0_L0 (mm_graph0.out[0], platform.sink[0]);
#ifdef __AIESIM__
int main(int argc, char** argv) {
    mm_graph0.init();
    mm_graph0.run(4);
    mm_graph0.end();
    return 0;
}
#endif