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
PLIO* LHS_in8_L0 = new PLIO("LHS_in8_L0", adf::plio_128_bits, "data/input0.txt",230);
PLIO* LHS_in9_L0 = new PLIO("LHS_in9_L0", adf::plio_128_bits, "data/input0.txt",230);
PLIO* LHS_in10_L0 = new PLIO("LHS_in10_L0", adf::plio_128_bits, "data/input0.txt",230);
PLIO* LHS_in11_L0 = new PLIO("LHS_in11_L0", adf::plio_128_bits, "data/input0.txt",230);
PLIO* LHS_in12_L0 = new PLIO("LHS_in12_L0", adf::plio_128_bits, "data/input0.txt",230);
PLIO* LHS_in13_L0 = new PLIO("LHS_in13_L0", adf::plio_128_bits, "data/input0.txt",230);
PLIO* LHS_in14_L0 = new PLIO("LHS_in14_L0", adf::plio_128_bits, "data/input0.txt",230);
PLIO* LHS_in15_L0 = new PLIO("LHS_in15_L0", adf::plio_128_bits, "data/input0.txt",230);
PLIO* LHS_in16_L0 = new PLIO("LHS_in16_L0", adf::plio_128_bits, "data/input0.txt",230);
PLIO* LHS_in17_L0 = new PLIO("LHS_in17_L0", adf::plio_128_bits, "data/input0.txt",230);
PLIO* LHS_in18_L0 = new PLIO("LHS_in18_L0", adf::plio_128_bits, "data/input0.txt",230);
PLIO* LHS_in19_L0 = new PLIO("LHS_in19_L0", adf::plio_128_bits, "data/input0.txt",230);
PLIO* LHS_in20_L0 = new PLIO("LHS_in20_L0", adf::plio_128_bits, "data/input0.txt",230);
PLIO* LHS_in21_L0 = new PLIO("LHS_in21_L0", adf::plio_128_bits, "data/input0.txt",230);
PLIO* LHS_in22_L0 = new PLIO("LHS_in22_L0", adf::plio_128_bits, "data/input0.txt",230);
PLIO* LHS_in23_L0 = new PLIO("LHS_in23_L0", adf::plio_128_bits, "data/input0.txt",230);
PLIO* LHS_in24_L0 = new PLIO("LHS_in24_L0", adf::plio_128_bits, "data/input0.txt",230);
PLIO* LHS_in25_L0 = new PLIO("LHS_in25_L0", adf::plio_128_bits, "data/input0.txt",230);
PLIO* LHS_in26_L0 = new PLIO("LHS_in26_L0", adf::plio_128_bits, "data/input0.txt",230);
PLIO* LHS_in27_L0 = new PLIO("LHS_in27_L0", adf::plio_128_bits, "data/input0.txt",230);
PLIO* LHS_in28_L0 = new PLIO("LHS_in28_L0", adf::plio_128_bits, "data/input0.txt",230);
PLIO* LHS_in29_L0 = new PLIO("LHS_in29_L0", adf::plio_128_bits, "data/input0.txt",230);
PLIO* LHS_in30_L0 = new PLIO("LHS_in30_L0", adf::plio_128_bits, "data/input0.txt",230);
PLIO* LHS_in31_L0 = new PLIO("LHS_in31_L0", adf::plio_128_bits, "data/input0.txt",230);
PLIO* LHS_in32_L0 = new PLIO("LHS_in32_L0", adf::plio_128_bits, "data/input0.txt",230);
PLIO* LHS_in33_L0 = new PLIO("LHS_in33_L0", adf::plio_128_bits, "data/input0.txt",230);
PLIO* LHS_in34_L0 = new PLIO("LHS_in34_L0", adf::plio_128_bits, "data/input0.txt",230);
PLIO* LHS_in35_L0 = new PLIO("LHS_in35_L0", adf::plio_128_bits, "data/input0.txt",230);
PLIO* LHS_in36_L0 = new PLIO("LHS_in36_L0", adf::plio_128_bits, "data/input0.txt",230);
PLIO* LHS_in37_L0 = new PLIO("LHS_in37_L0", adf::plio_128_bits, "data/input0.txt",230);
PLIO* LHS_in38_L0 = new PLIO("LHS_in38_L0", adf::plio_128_bits, "data/input0.txt",230);
PLIO* LHS_in39_L0 = new PLIO("LHS_in39_L0", adf::plio_128_bits, "data/input0.txt",230);
PLIO* LHS_in40_L0 = new PLIO("LHS_in40_L0", adf::plio_128_bits, "data/input0.txt",230);
PLIO* LHS_in41_L0 = new PLIO("LHS_in41_L0", adf::plio_128_bits, "data/input0.txt",230);
PLIO* LHS_in42_L0 = new PLIO("LHS_in42_L0", adf::plio_128_bits, "data/input0.txt",230);
PLIO* LHS_in43_L0 = new PLIO("LHS_in43_L0", adf::plio_128_bits, "data/input0.txt",230);
PLIO* LHS_in44_L0 = new PLIO("LHS_in44_L0", adf::plio_128_bits, "data/input0.txt",230);
PLIO* LHS_in45_L0 = new PLIO("LHS_in45_L0", adf::plio_128_bits, "data/input0.txt",230);
PLIO* LHS_in46_L0 = new PLIO("LHS_in46_L0", adf::plio_128_bits, "data/input0.txt",230);
PLIO* LHS_in47_L0 = new PLIO("LHS_in47_L0", adf::plio_128_bits, "data/input0.txt",230);

PLIO* RHS_in0_L0 = new PLIO("RHS_in0_L0", adf::plio_128_bits, "data/input1.txt",230);
PLIO* RHS_in1_L0 = new PLIO("RHS_in1_L0", adf::plio_128_bits, "data/input1.txt",230);
PLIO* RHS_in2_L0 = new PLIO("RHS_in2_L0", adf::plio_128_bits, "data/input1.txt",230);
PLIO* RHS_in3_L0 = new PLIO("RHS_in3_L0", adf::plio_128_bits, "data/input1.txt",230);
PLIO* RHS_in4_L0 = new PLIO("RHS_in4_L0", adf::plio_128_bits, "data/input1.txt",230);
PLIO* RHS_in5_L0 = new PLIO("RHS_in5_L0", adf::plio_128_bits, "data/input1.txt",230);
PLIO* RHS_in6_L0 = new PLIO("RHS_in6_L0", adf::plio_128_bits, "data/input1.txt",230);
PLIO* RHS_in7_L0 = new PLIO("RHS_in7_L0", adf::plio_128_bits, "data/input1.txt",230);
PLIO* RHS_in8_L0 = new PLIO("RHS_in8_L0", adf::plio_128_bits, "data/input1.txt",230);
PLIO* RHS_in9_L0 = new PLIO("RHS_in9_L0", adf::plio_128_bits, "data/input1.txt",230);
PLIO* RHS_in10_L0 = new PLIO("RHS_in10_L0", adf::plio_128_bits, "data/input1.txt",230);
PLIO* RHS_in11_L0 = new PLIO("RHS_in11_L0", adf::plio_128_bits, "data/input1.txt",230);
PLIO* RHS_in12_L0 = new PLIO("RHS_in12_L0", adf::plio_128_bits, "data/input1.txt",230);
PLIO* RHS_in13_L0 = new PLIO("RHS_in13_L0", adf::plio_128_bits, "data/input1.txt",230);
PLIO* RHS_in14_L0 = new PLIO("RHS_in14_L0", adf::plio_128_bits, "data/input1.txt",230);
PLIO* RHS_in15_L0 = new PLIO("RHS_in15_L0", adf::plio_128_bits, "data/input1.txt",230);
PLIO* RHS_in16_L0 = new PLIO("RHS_in16_L0", adf::plio_128_bits, "data/input1.txt",230);
PLIO* RHS_in17_L0 = new PLIO("RHS_in17_L0", adf::plio_128_bits, "data/input1.txt",230);
PLIO* RHS_in18_L0 = new PLIO("RHS_in18_L0", adf::plio_128_bits, "data/input1.txt",230);
PLIO* RHS_in19_L0 = new PLIO("RHS_in19_L0", adf::plio_128_bits, "data/input1.txt",230);
PLIO* RHS_in20_L0 = new PLIO("RHS_in20_L0", adf::plio_128_bits, "data/input1.txt",230);
PLIO* RHS_in21_L0 = new PLIO("RHS_in21_L0", adf::plio_128_bits, "data/input1.txt",230);
PLIO* RHS_in22_L0 = new PLIO("RHS_in22_L0", adf::plio_128_bits, "data/input1.txt",230);
PLIO* RHS_in23_L0 = new PLIO("RHS_in23_L0", adf::plio_128_bits, "data/input1.txt",230);
PLIO* RHS_in24_L0 = new PLIO("RHS_in24_L0", adf::plio_128_bits, "data/input1.txt",230);
PLIO* RHS_in25_L0 = new PLIO("RHS_in25_L0", adf::plio_128_bits, "data/input1.txt",230);
PLIO* RHS_in26_L0 = new PLIO("RHS_in26_L0", adf::plio_128_bits, "data/input1.txt",230);
PLIO* RHS_in27_L0 = new PLIO("RHS_in27_L0", adf::plio_128_bits, "data/input1.txt",230);
PLIO* RHS_in28_L0 = new PLIO("RHS_in28_L0", adf::plio_128_bits, "data/input1.txt",230);
PLIO* RHS_in29_L0 = new PLIO("RHS_in29_L0", adf::plio_128_bits, "data/input1.txt",230);
PLIO* RHS_in30_L0 = new PLIO("RHS_in30_L0", adf::plio_128_bits, "data/input1.txt",230);
PLIO* RHS_in31_L0 = new PLIO("RHS_in31_L0", adf::plio_128_bits, "data/input1.txt",230);
PLIO* RHS_in32_L0 = new PLIO("RHS_in32_L0", adf::plio_128_bits, "data/input1.txt",230);
PLIO* RHS_in33_L0 = new PLIO("RHS_in33_L0", adf::plio_128_bits, "data/input1.txt",230);
PLIO* RHS_in34_L0 = new PLIO("RHS_in34_L0", adf::plio_128_bits, "data/input1.txt",230);
PLIO* RHS_in35_L0 = new PLIO("RHS_in35_L0", adf::plio_128_bits, "data/input1.txt",230);
PLIO* RHS_in36_L0 = new PLIO("RHS_in36_L0", adf::plio_128_bits, "data/input1.txt",230);
PLIO* RHS_in37_L0 = new PLIO("RHS_in37_L0", adf::plio_128_bits, "data/input1.txt",230);
PLIO* RHS_in38_L0 = new PLIO("RHS_in38_L0", adf::plio_128_bits, "data/input1.txt",230);
PLIO* RHS_in39_L0 = new PLIO("RHS_in39_L0", adf::plio_128_bits, "data/input1.txt",230);
PLIO* RHS_in40_L0 = new PLIO("RHS_in40_L0", adf::plio_128_bits, "data/input1.txt",230);
PLIO* RHS_in41_L0 = new PLIO("RHS_in41_L0", adf::plio_128_bits, "data/input1.txt",230);
PLIO* RHS_in42_L0 = new PLIO("RHS_in42_L0", adf::plio_128_bits, "data/input1.txt",230);
PLIO* RHS_in43_L0 = new PLIO("RHS_in43_L0", adf::plio_128_bits, "data/input1.txt",230);
PLIO* RHS_in44_L0 = new PLIO("RHS_in44_L0", adf::plio_128_bits, "data/input1.txt",230);
PLIO* RHS_in45_L0 = new PLIO("RHS_in45_L0", adf::plio_128_bits, "data/input1.txt",230);
PLIO* RHS_in46_L0 = new PLIO("RHS_in46_L0", adf::plio_128_bits, "data/input1.txt",230);
PLIO* RHS_in47_L0 = new PLIO("RHS_in47_L0", adf::plio_128_bits, "data/input1.txt",230);
PLIO* RHS_in48_L0 = new PLIO("RHS_in48_L0", adf::plio_128_bits, "data/input1.txt",230);
PLIO* RHS_in49_L0 = new PLIO("RHS_in49_L0", adf::plio_128_bits, "data/input1.txt",230);
PLIO* RHS_in50_L0 = new PLIO("RHS_in50_L0", adf::plio_128_bits, "data/input1.txt",230);
PLIO* RHS_in51_L0 = new PLIO("RHS_in51_L0", adf::plio_128_bits, "data/input1.txt",230);
PLIO* RHS_in52_L0 = new PLIO("RHS_in52_L0", adf::plio_128_bits, "data/input1.txt",230);
PLIO* RHS_in53_L0 = new PLIO("RHS_in53_L0", adf::plio_128_bits, "data/input1.txt",230);
PLIO* RHS_in54_L0 = new PLIO("RHS_in54_L0", adf::plio_128_bits, "data/input1.txt",230);
PLIO* RHS_in55_L0 = new PLIO("RHS_in55_L0", adf::plio_128_bits, "data/input1.txt",230);
PLIO* RHS_in56_L0 = new PLIO("RHS_in56_L0", adf::plio_128_bits, "data/input1.txt",230);
PLIO* RHS_in57_L0 = new PLIO("RHS_in57_L0", adf::plio_128_bits, "data/input1.txt",230);
PLIO* RHS_in58_L0 = new PLIO("RHS_in58_L0", adf::plio_128_bits, "data/input1.txt",230);
PLIO* RHS_in59_L0 = new PLIO("RHS_in59_L0", adf::plio_128_bits, "data/input1.txt",230);
PLIO* RHS_in60_L0 = new PLIO("RHS_in60_L0", adf::plio_128_bits, "data/input1.txt",230);
PLIO* RHS_in61_L0 = new PLIO("RHS_in61_L0", adf::plio_128_bits, "data/input1.txt",230);
PLIO* RHS_in62_L0 = new PLIO("RHS_in62_L0", adf::plio_128_bits, "data/input1.txt",230);
PLIO* RHS_in63_L0 = new PLIO("RHS_in63_L0", adf::plio_128_bits, "data/input1.txt",230);
PLIO* RHS_in64_L0 = new PLIO("RHS_in64_L0", adf::plio_128_bits, "data/input1.txt",230);
PLIO* RHS_in65_L0 = new PLIO("RHS_in65_L0", adf::plio_128_bits, "data/input1.txt",230);
PLIO* RHS_in66_L0 = new PLIO("RHS_in66_L0", adf::plio_128_bits, "data/input1.txt",230);
PLIO* RHS_in67_L0 = new PLIO("RHS_in67_L0", adf::plio_128_bits, "data/input1.txt",230);
PLIO* RHS_in68_L0 = new PLIO("RHS_in68_L0", adf::plio_128_bits, "data/input1.txt",230);
PLIO* RHS_in69_L0 = new PLIO("RHS_in69_L0", adf::plio_128_bits, "data/input1.txt",230);
PLIO* RHS_in70_L0 = new PLIO("RHS_in70_L0", adf::plio_128_bits, "data/input1.txt",230);
PLIO* RHS_in71_L0 = new PLIO("RHS_in71_L0", adf::plio_128_bits, "data/input1.txt",230);
PLIO* RHS_in72_L0 = new PLIO("RHS_in72_L0", adf::plio_128_bits, "data/input1.txt",230);
PLIO* RHS_in73_L0 = new PLIO("RHS_in73_L0", adf::plio_128_bits, "data/input1.txt",230);
PLIO* RHS_in74_L0 = new PLIO("RHS_in74_L0", adf::plio_128_bits, "data/input1.txt",230);
PLIO* RHS_in75_L0 = new PLIO("RHS_in75_L0", adf::plio_128_bits, "data/input1.txt",230);
PLIO* RHS_in76_L0 = new PLIO("RHS_in76_L0", adf::plio_128_bits, "data/input1.txt",230);
PLIO* RHS_in77_L0 = new PLIO("RHS_in77_L0", adf::plio_128_bits, "data/input1.txt",230);
PLIO* RHS_in78_L0 = new PLIO("RHS_in78_L0", adf::plio_128_bits, "data/input1.txt",230);
PLIO* RHS_in79_L0 = new PLIO("RHS_in79_L0", adf::plio_128_bits, "data/input1.txt",230);
PLIO* RHS_in80_L0 = new PLIO("RHS_in80_L0", adf::plio_128_bits, "data/input1.txt",230);
PLIO* RHS_in81_L0 = new PLIO("RHS_in81_L0", adf::plio_128_bits, "data/input1.txt",230);
PLIO* RHS_in82_L0 = new PLIO("RHS_in82_L0", adf::plio_128_bits, "data/input1.txt",230);
PLIO* RHS_in83_L0 = new PLIO("RHS_in83_L0", adf::plio_128_bits, "data/input1.txt",230);
PLIO* RHS_in84_L0 = new PLIO("RHS_in84_L0", adf::plio_128_bits, "data/input1.txt",230);
PLIO* RHS_in85_L0 = new PLIO("RHS_in85_L0", adf::plio_128_bits, "data/input1.txt",230);
PLIO* RHS_in86_L0 = new PLIO("RHS_in86_L0", adf::plio_128_bits, "data/input1.txt",230);
PLIO* RHS_in87_L0 = new PLIO("RHS_in87_L0", adf::plio_128_bits, "data/input1.txt",230);
PLIO* RHS_in88_L0 = new PLIO("RHS_in88_L0", adf::plio_128_bits, "data/input1.txt",230);
PLIO* RHS_in89_L0 = new PLIO("RHS_in89_L0", adf::plio_128_bits, "data/input1.txt",230);
PLIO* RHS_in90_L0 = new PLIO("RHS_in90_L0", adf::plio_128_bits, "data/input1.txt",230);
PLIO* RHS_in91_L0 = new PLIO("RHS_in91_L0", adf::plio_128_bits, "data/input1.txt",230);
PLIO* RHS_in92_L0 = new PLIO("RHS_in92_L0", adf::plio_128_bits, "data/input1.txt",230);
PLIO* RHS_in93_L0 = new PLIO("RHS_in93_L0", adf::plio_128_bits, "data/input1.txt",230);
PLIO* RHS_in94_L0 = new PLIO("RHS_in94_L0", adf::plio_128_bits, "data/input1.txt",230);
PLIO* RHS_in95_L0 = new PLIO("RHS_in95_L0", adf::plio_128_bits, "data/input1.txt",230);
PLIO* out0_L0 = new PLIO("out0_L0", adf::plio_128_bits, "data/output0.txt",230);
PLIO* out1_L0 = new PLIO("out1_L0", adf::plio_128_bits, "data/output1.txt",230);
PLIO* out2_L0 = new PLIO("out2_L0", adf::plio_128_bits, "data/output2.txt",230);
PLIO* out3_L0 = new PLIO("out3_L0", adf::plio_128_bits, "data/output3.txt",230);
PLIO* out4_L0 = new PLIO("out4_L0", adf::plio_128_bits, "data/output4.txt",230);
PLIO* out5_L0 = new PLIO("out5_L0", adf::plio_128_bits, "data/output5.txt",230);
PLIO* out6_L0 = new PLIO("out6_L0", adf::plio_128_bits, "data/output6.txt",230);
PLIO* out7_L0 = new PLIO("out7_L0", adf::plio_128_bits, "data/output7.txt",230);
PLIO* out8_L0 = new PLIO("out8_L0", adf::plio_128_bits, "data/output8.txt",230);
PLIO* out9_L0 = new PLIO("out9_L0", adf::plio_128_bits, "data/output9.txt",230);
PLIO* out10_L0 = new PLIO("out10_L0", adf::plio_128_bits, "data/output10.txt",230);
PLIO* out11_L0 = new PLIO("out11_L0", adf::plio_128_bits, "data/output11.txt",230);
PLIO* out12_L0 = new PLIO("out12_L0", adf::plio_128_bits, "data/output12.txt",230);
PLIO* out13_L0 = new PLIO("out13_L0", adf::plio_128_bits, "data/output13.txt",230);
PLIO* out14_L0 = new PLIO("out14_L0", adf::plio_128_bits, "data/output14.txt",230);
PLIO* out15_L0 = new PLIO("out15_L0", adf::plio_128_bits, "data/output15.txt",230);

simulation::platform<144, 16> platform(
LHS_in0_L0,
LHS_in1_L0,
LHS_in2_L0,
LHS_in3_L0,
LHS_in4_L0,
LHS_in5_L0,
LHS_in6_L0,
LHS_in7_L0,
LHS_in8_L0,
LHS_in9_L0,
LHS_in10_L0,
LHS_in11_L0,
LHS_in12_L0,
LHS_in13_L0,
LHS_in14_L0,
LHS_in15_L0,
LHS_in16_L0,
LHS_in17_L0,
LHS_in18_L0,
LHS_in19_L0,
LHS_in20_L0,
LHS_in21_L0,
LHS_in22_L0,
LHS_in23_L0,
LHS_in24_L0,
LHS_in25_L0,
LHS_in26_L0,
LHS_in27_L0,
LHS_in28_L0,
LHS_in29_L0,
LHS_in30_L0,
LHS_in31_L0,
LHS_in32_L0,
LHS_in33_L0,
LHS_in34_L0,
LHS_in35_L0,
LHS_in36_L0,
LHS_in37_L0,
LHS_in38_L0,
LHS_in39_L0,
LHS_in40_L0,
LHS_in41_L0,
LHS_in42_L0,
LHS_in43_L0,
LHS_in44_L0,
LHS_in45_L0,
LHS_in46_L0,
LHS_in47_L0,
RHS_in0_L0, 
RHS_in1_L0, 
RHS_in2_L0, 
RHS_in3_L0, 
RHS_in4_L0, 
RHS_in5_L0, 
RHS_in6_L0, 
RHS_in7_L0, 
RHS_in8_L0, 
RHS_in9_L0, 
RHS_in10_L0, 
RHS_in11_L0, 
RHS_in12_L0, 
RHS_in13_L0, 
RHS_in14_L0, 
RHS_in15_L0, 
RHS_in16_L0, 
RHS_in17_L0, 
RHS_in18_L0, 
RHS_in19_L0, 
RHS_in20_L0, 
RHS_in21_L0, 
RHS_in22_L0, 
RHS_in23_L0, 
RHS_in24_L0, 
RHS_in25_L0, 
RHS_in26_L0, 
RHS_in27_L0, 
RHS_in28_L0, 
RHS_in29_L0, 
RHS_in30_L0, 
RHS_in31_L0, 
RHS_in32_L0, 
RHS_in33_L0, 
RHS_in34_L0, 
RHS_in35_L0, 
RHS_in36_L0, 
RHS_in37_L0, 
RHS_in38_L0, 
RHS_in39_L0, 
RHS_in40_L0, 
RHS_in41_L0, 
RHS_in42_L0, 
RHS_in43_L0, 
RHS_in44_L0, 
RHS_in45_L0, 
RHS_in46_L0, 
RHS_in47_L0, 
RHS_in48_L0, 
RHS_in49_L0, 
RHS_in50_L0, 
RHS_in51_L0, 
RHS_in52_L0, 
RHS_in53_L0, 
RHS_in54_L0, 
RHS_in55_L0, 
RHS_in56_L0, 
RHS_in57_L0, 
RHS_in58_L0, 
RHS_in59_L0, 
RHS_in60_L0, 
RHS_in61_L0, 
RHS_in62_L0, 
RHS_in63_L0, 
RHS_in64_L0, 
RHS_in65_L0, 
RHS_in66_L0, 
RHS_in67_L0, 
RHS_in68_L0, 
RHS_in69_L0, 
RHS_in70_L0, 
RHS_in71_L0, 
RHS_in72_L0, 
RHS_in73_L0, 
RHS_in74_L0, 
RHS_in75_L0, 
RHS_in76_L0, 
RHS_in77_L0, 
RHS_in78_L0, 
RHS_in79_L0, 
RHS_in80_L0, 
RHS_in81_L0, 
RHS_in82_L0, 
RHS_in83_L0, 
RHS_in84_L0, 
RHS_in85_L0, 
RHS_in86_L0, 
RHS_in87_L0, 
RHS_in88_L0, 
RHS_in89_L0, 
RHS_in90_L0, 
RHS_in91_L0, 
RHS_in92_L0, 
RHS_in93_L0, 
RHS_in94_L0, 
RHS_in95_L0, 
out0_L0,
out1_L0,
out2_L0,
out3_L0,
out4_L0,
out5_L0,
out6_L0,
out7_L0,
out8_L0,
out9_L0,
out10_L0,
out11_L0,
out12_L0,
out13_L0,
out14_L0,
out15_L0 
);


mm_x4_x12_x8_graph0  mm_graph0;


connect<> net_lhs_in0_L0 (platform.src[0], mm_graph0.in_lhs[0][0]);
connect<> net_lhs_in1_L0 (platform.src[1], mm_graph0.in_lhs[0][1]);
connect<> net_lhs_in2_L0 (platform.src[2], mm_graph0.in_lhs[0][2]);
connect<> net_lhs_in3_L0 (platform.src[3], mm_graph0.in_lhs[0][3]);
connect<> net_lhs_in4_L0 (platform.src[4], mm_graph0.in_lhs[0][4]);
connect<> net_lhs_in5_L0 (platform.src[5], mm_graph0.in_lhs[0][5]);
connect<> net_lhs_in6_L0 (platform.src[6], mm_graph0.in_lhs[1][0]);
connect<> net_lhs_in7_L0 (platform.src[7], mm_graph0.in_lhs[1][1]);
connect<> net_lhs_in8_L0 (platform.src[8], mm_graph0.in_lhs[1][2]);
connect<> net_lhs_in9_L0 (platform.src[9], mm_graph0.in_lhs[1][3]);
connect<> net_lhs_in10_L0 (platform.src[10], mm_graph0.in_lhs[1][4]);
connect<> net_lhs_in11_L0 (platform.src[11], mm_graph0.in_lhs[1][5]);
connect<> net_lhs_in12_L0 (platform.src[12], mm_graph0.in_lhs[2][0]);
connect<> net_lhs_in13_L0 (platform.src[13], mm_graph0.in_lhs[2][1]);
connect<> net_lhs_in14_L0 (platform.src[14], mm_graph0.in_lhs[2][2]);
connect<> net_lhs_in15_L0 (platform.src[15], mm_graph0.in_lhs[2][3]);
connect<> net_lhs_in16_L0 (platform.src[16], mm_graph0.in_lhs[2][4]);
connect<> net_lhs_in17_L0 (platform.src[17], mm_graph0.in_lhs[2][5]);
connect<> net_lhs_in18_L0 (platform.src[18], mm_graph0.in_lhs[3][0]);
connect<> net_lhs_in19_L0 (platform.src[19], mm_graph0.in_lhs[3][1]);
connect<> net_lhs_in20_L0 (platform.src[20], mm_graph0.in_lhs[3][2]);
connect<> net_lhs_in21_L0 (platform.src[21], mm_graph0.in_lhs[3][3]);
connect<> net_lhs_in22_L0 (platform.src[22], mm_graph0.in_lhs[3][4]);
connect<> net_lhs_in23_L0 (platform.src[23], mm_graph0.in_lhs[3][5]);
connect<> net_lhs_in24_L0 (platform.src[24], mm_graph0.in_lhs[4][0]);
connect<> net_lhs_in25_L0 (platform.src[25], mm_graph0.in_lhs[4][1]);
connect<> net_lhs_in26_L0 (platform.src[26], mm_graph0.in_lhs[4][2]);
connect<> net_lhs_in27_L0 (platform.src[27], mm_graph0.in_lhs[4][3]);
connect<> net_lhs_in28_L0 (platform.src[28], mm_graph0.in_lhs[4][4]);
connect<> net_lhs_in29_L0 (platform.src[29], mm_graph0.in_lhs[4][5]);
connect<> net_lhs_in30_L0 (platform.src[30], mm_graph0.in_lhs[5][0]);
connect<> net_lhs_in31_L0 (platform.src[31], mm_graph0.in_lhs[5][1]);
connect<> net_lhs_in32_L0 (platform.src[32], mm_graph0.in_lhs[5][2]);
connect<> net_lhs_in33_L0 (platform.src[33], mm_graph0.in_lhs[5][3]);
connect<> net_lhs_in34_L0 (platform.src[34], mm_graph0.in_lhs[5][4]);
connect<> net_lhs_in35_L0 (platform.src[35], mm_graph0.in_lhs[5][5]);
connect<> net_lhs_in36_L0 (platform.src[36], mm_graph0.in_lhs[6][0]);
connect<> net_lhs_in37_L0 (platform.src[37], mm_graph0.in_lhs[6][1]);
connect<> net_lhs_in38_L0 (platform.src[38], mm_graph0.in_lhs[6][2]);
connect<> net_lhs_in39_L0 (platform.src[39], mm_graph0.in_lhs[6][3]);
connect<> net_lhs_in40_L0 (platform.src[40], mm_graph0.in_lhs[6][4]);
connect<> net_lhs_in41_L0 (platform.src[41], mm_graph0.in_lhs[6][5]);
connect<> net_lhs_in42_L0 (platform.src[42], mm_graph0.in_lhs[7][0]);
connect<> net_lhs_in43_L0 (platform.src[43], mm_graph0.in_lhs[7][1]);
connect<> net_lhs_in44_L0 (platform.src[44], mm_graph0.in_lhs[7][2]);
connect<> net_lhs_in45_L0 (platform.src[45], mm_graph0.in_lhs[7][3]);
connect<> net_lhs_in46_L0 (platform.src[46], mm_graph0.in_lhs[7][4]);
connect<> net_lhs_in47_L0 (platform.src[47], mm_graph0.in_lhs[7][5]);

connect<> net_rhs_in0_L0 (platform.src[48], mm_graph0.in_rhs[0][0]);
connect<> net_rhs_in1_L0 (platform.src[49], mm_graph0.in_rhs[0][1]);
connect<> net_rhs_in2_L0 (platform.src[50], mm_graph0.in_rhs[0][2]);
connect<> net_rhs_in3_L0 (platform.src[51], mm_graph0.in_rhs[0][3]);
connect<> net_rhs_in4_L0 (platform.src[52], mm_graph0.in_rhs[0][4]);
connect<> net_rhs_in5_L0 (platform.src[53], mm_graph0.in_rhs[0][5]);
connect<> net_rhs_in6_L0 (platform.src[54], mm_graph0.in_rhs[1][0]);
connect<> net_rhs_in7_L0 (platform.src[55], mm_graph0.in_rhs[1][1]);
connect<> net_rhs_in8_L0 (platform.src[56], mm_graph0.in_rhs[1][2]);
connect<> net_rhs_in9_L0 (platform.src[57], mm_graph0.in_rhs[1][3]);
connect<> net_rhs_in10_L0 (platform.src[58], mm_graph0.in_rhs[1][4]);
connect<> net_rhs_in11_L0 (platform.src[59], mm_graph0.in_rhs[1][5]);
connect<> net_rhs_in12_L0 (platform.src[60], mm_graph0.in_rhs[2][0]);
connect<> net_rhs_in13_L0 (platform.src[61], mm_graph0.in_rhs[2][1]);
connect<> net_rhs_in14_L0 (platform.src[62], mm_graph0.in_rhs[2][2]);
connect<> net_rhs_in15_L0 (platform.src[63], mm_graph0.in_rhs[2][3]);
connect<> net_rhs_in16_L0 (platform.src[64], mm_graph0.in_rhs[2][4]);
connect<> net_rhs_in17_L0 (platform.src[65], mm_graph0.in_rhs[2][5]);
connect<> net_rhs_in18_L0 (platform.src[66], mm_graph0.in_rhs[3][0]);
connect<> net_rhs_in19_L0 (platform.src[67], mm_graph0.in_rhs[3][1]);
connect<> net_rhs_in20_L0 (platform.src[68], mm_graph0.in_rhs[3][2]);
connect<> net_rhs_in21_L0 (platform.src[69], mm_graph0.in_rhs[3][3]);
connect<> net_rhs_in22_L0 (platform.src[70], mm_graph0.in_rhs[3][4]);
connect<> net_rhs_in23_L0 (platform.src[71], mm_graph0.in_rhs[3][5]);
connect<> net_rhs_in24_L0 (platform.src[72], mm_graph0.in_rhs[4][0]);
connect<> net_rhs_in25_L0 (platform.src[73], mm_graph0.in_rhs[4][1]);
connect<> net_rhs_in26_L0 (platform.src[74], mm_graph0.in_rhs[4][2]);
connect<> net_rhs_in27_L0 (platform.src[75], mm_graph0.in_rhs[4][3]);
connect<> net_rhs_in28_L0 (platform.src[76], mm_graph0.in_rhs[4][4]);
connect<> net_rhs_in29_L0 (platform.src[77], mm_graph0.in_rhs[4][5]);
connect<> net_rhs_in30_L0 (platform.src[78], mm_graph0.in_rhs[5][0]);
connect<> net_rhs_in31_L0 (platform.src[79], mm_graph0.in_rhs[5][1]);
connect<> net_rhs_in32_L0 (platform.src[80], mm_graph0.in_rhs[5][2]);
connect<> net_rhs_in33_L0 (platform.src[81], mm_graph0.in_rhs[5][3]);
connect<> net_rhs_in34_L0 (platform.src[82], mm_graph0.in_rhs[5][4]);
connect<> net_rhs_in35_L0 (platform.src[83], mm_graph0.in_rhs[5][5]);
connect<> net_rhs_in36_L0 (platform.src[84], mm_graph0.in_rhs[6][0]);
connect<> net_rhs_in37_L0 (platform.src[85], mm_graph0.in_rhs[6][1]);
connect<> net_rhs_in38_L0 (platform.src[86], mm_graph0.in_rhs[6][2]);
connect<> net_rhs_in39_L0 (platform.src[87], mm_graph0.in_rhs[6][3]);
connect<> net_rhs_in40_L0 (platform.src[88], mm_graph0.in_rhs[6][4]);
connect<> net_rhs_in41_L0 (platform.src[89], mm_graph0.in_rhs[6][5]);
connect<> net_rhs_in42_L0 (platform.src[90], mm_graph0.in_rhs[7][0]);
connect<> net_rhs_in43_L0 (platform.src[91], mm_graph0.in_rhs[7][1]);
connect<> net_rhs_in44_L0 (platform.src[92], mm_graph0.in_rhs[7][2]);
connect<> net_rhs_in45_L0 (platform.src[93], mm_graph0.in_rhs[7][3]);
connect<> net_rhs_in46_L0 (platform.src[94], mm_graph0.in_rhs[7][4]);
connect<> net_rhs_in47_L0 (platform.src[95], mm_graph0.in_rhs[7][5]);
connect<> net_rhs_in48_L0 (platform.src[96], mm_graph0.in_rhs[8][0]);
connect<> net_rhs_in49_L0 (platform.src[97], mm_graph0.in_rhs[8][1]);
connect<> net_rhs_in50_L0 (platform.src[98], mm_graph0.in_rhs[8][2]);
connect<> net_rhs_in51_L0 (platform.src[99], mm_graph0.in_rhs[8][3]);
connect<> net_rhs_in52_L0 (platform.src[100], mm_graph0.in_rhs[8][4]);
connect<> net_rhs_in53_L0 (platform.src[101], mm_graph0.in_rhs[8][5]);
connect<> net_rhs_in54_L0 (platform.src[102], mm_graph0.in_rhs[9][0]);
connect<> net_rhs_in55_L0 (platform.src[103], mm_graph0.in_rhs[9][1]);
connect<> net_rhs_in56_L0 (platform.src[104], mm_graph0.in_rhs[9][2]);
connect<> net_rhs_in57_L0 (platform.src[105], mm_graph0.in_rhs[9][3]);
connect<> net_rhs_in58_L0 (platform.src[106], mm_graph0.in_rhs[9][4]);
connect<> net_rhs_in59_L0 (platform.src[107], mm_graph0.in_rhs[9][5]);
connect<> net_rhs_in60_L0 (platform.src[108], mm_graph0.in_rhs[10][0]);
connect<> net_rhs_in61_L0 (platform.src[109], mm_graph0.in_rhs[10][1]);
connect<> net_rhs_in62_L0 (platform.src[110], mm_graph0.in_rhs[10][2]);
connect<> net_rhs_in63_L0 (platform.src[111], mm_graph0.in_rhs[10][3]);
connect<> net_rhs_in64_L0 (platform.src[112], mm_graph0.in_rhs[10][4]);
connect<> net_rhs_in65_L0 (platform.src[113], mm_graph0.in_rhs[10][5]);
connect<> net_rhs_in66_L0 (platform.src[114], mm_graph0.in_rhs[11][0]);
connect<> net_rhs_in67_L0 (platform.src[115], mm_graph0.in_rhs[11][1]);
connect<> net_rhs_in68_L0 (platform.src[116], mm_graph0.in_rhs[11][2]);
connect<> net_rhs_in69_L0 (platform.src[117], mm_graph0.in_rhs[11][3]);
connect<> net_rhs_in70_L0 (platform.src[118], mm_graph0.in_rhs[11][4]);
connect<> net_rhs_in71_L0 (platform.src[119], mm_graph0.in_rhs[11][5]);
connect<> net_rhs_in72_L0 (platform.src[120], mm_graph0.in_rhs[12][0]);
connect<> net_rhs_in73_L0 (platform.src[121], mm_graph0.in_rhs[12][1]);
connect<> net_rhs_in74_L0 (platform.src[122], mm_graph0.in_rhs[12][2]);
connect<> net_rhs_in75_L0 (platform.src[123], mm_graph0.in_rhs[12][3]);
connect<> net_rhs_in76_L0 (platform.src[124], mm_graph0.in_rhs[12][4]);
connect<> net_rhs_in77_L0 (platform.src[125], mm_graph0.in_rhs[12][5]);
connect<> net_rhs_in78_L0 (platform.src[126], mm_graph0.in_rhs[13][0]);
connect<> net_rhs_in79_L0 (platform.src[127], mm_graph0.in_rhs[13][1]);
connect<> net_rhs_in80_L0 (platform.src[128], mm_graph0.in_rhs[13][2]);
connect<> net_rhs_in81_L0 (platform.src[129], mm_graph0.in_rhs[13][3]);
connect<> net_rhs_in82_L0 (platform.src[130], mm_graph0.in_rhs[13][4]);
connect<> net_rhs_in83_L0 (platform.src[131], mm_graph0.in_rhs[13][5]);
connect<> net_rhs_in84_L0 (platform.src[132], mm_graph0.in_rhs[14][0]);
connect<> net_rhs_in85_L0 (platform.src[133], mm_graph0.in_rhs[14][1]);
connect<> net_rhs_in86_L0 (platform.src[134], mm_graph0.in_rhs[14][2]);
connect<> net_rhs_in87_L0 (platform.src[135], mm_graph0.in_rhs[14][3]);
connect<> net_rhs_in88_L0 (platform.src[136], mm_graph0.in_rhs[14][4]);
connect<> net_rhs_in89_L0 (platform.src[137], mm_graph0.in_rhs[14][5]);
connect<> net_rhs_in90_L0 (platform.src[138], mm_graph0.in_rhs[15][0]);
connect<> net_rhs_in91_L0 (platform.src[139], mm_graph0.in_rhs[15][1]);
connect<> net_rhs_in92_L0 (platform.src[140], mm_graph0.in_rhs[15][2]);
connect<> net_rhs_in93_L0 (platform.src[141], mm_graph0.in_rhs[15][3]);
connect<> net_rhs_in94_L0 (platform.src[142], mm_graph0.in_rhs[15][4]);
connect<> net_rhs_in95_L0 (platform.src[143], mm_graph0.in_rhs[15][5]);
connect<> net_out0_L0 (mm_graph0.out[0], platform.sink[0]);
connect<> net_out1_L0 (mm_graph0.out[1], platform.sink[1]);
connect<> net_out2_L0 (mm_graph0.out[2], platform.sink[2]);
connect<> net_out3_L0 (mm_graph0.out[3], platform.sink[3]);
connect<> net_out4_L0 (mm_graph0.out[4], platform.sink[4]);
connect<> net_out5_L0 (mm_graph0.out[5], platform.sink[5]);
connect<> net_out6_L0 (mm_graph0.out[6], platform.sink[6]);
connect<> net_out7_L0 (mm_graph0.out[7], platform.sink[7]);
connect<> net_out8_L0 (mm_graph0.out[8], platform.sink[8]);
connect<> net_out9_L0 (mm_graph0.out[9], platform.sink[9]);
connect<> net_out10_L0 (mm_graph0.out[10], platform.sink[10]);
connect<> net_out11_L0 (mm_graph0.out[11], platform.sink[11]);
connect<> net_out12_L0 (mm_graph0.out[12], platform.sink[12]);
connect<> net_out13_L0 (mm_graph0.out[13], platform.sink[13]);
connect<> net_out14_L0 (mm_graph0.out[14], platform.sink[14]);
connect<> net_out15_L0 (mm_graph0.out[15], platform.sink[15]);
#ifdef __AIESIM__
int main(int argc, char** argv) {
    mm_graph0.init();
    mm_graph0.run(4);
    mm_graph0.end();
    return 0;
}
#endif