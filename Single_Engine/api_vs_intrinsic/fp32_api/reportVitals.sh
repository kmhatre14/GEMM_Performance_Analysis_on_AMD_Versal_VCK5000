# Vitis aie simulator
# list=(
# 'aie_fp32_16x16x16'
# )

list=(
'aie_fp32_32x32x32'
'aie_fp32_64x64x64'
'aie_fp32_16x16x16'
'aie_fp32_64x32x64'
'aie_fp32_32x64x32'
'aie_fp32_64x64x32'
'aie_fp32_32x64x64'
'aie_fp32_32x16x32'
'aie_fp32_16x32x16'
'aie_fp32_32x32x16'
'aie_fp32_16x32x32'
'aie_fp32_128x16x128'
'aie_fp32_16x128x16'
'aie_fp32_128x128x16'
'aie_fp32_16x128x128'
'aie_fp32_64x16x64'
'aie_fp32_16x64x16'
'aie_fp32_64x64x16'
'aie_fp32_16x64x64'
'aie_fp32_128x8x128'
'aie_fp32_8x128x8'
'aie_fp32_128x128x8'
'aie_fp32_8x128x128'
'aie_fp32_64x8x64'
'aie_fp32_8x64x8'
'aie_fp32_64x64x8'
'aie_fp32_8x64x64'
'aie_fp32_32x8x32'
'aie_fp32_8x32x8'
'aie_fp32_32x32x8'
'aie_fp32_8x32x32'
)



for i in "${list[@]}"
do
    # echo -n "Collecting_Execution_Cyles_for_$i"
    # sed '20!d' aie_sim_$i/profile_instr_23_0.txt
    # echo ""

    echo -n "Collecting_Program_memory_for_$i"
    grep -i "sysmem" Work_$i/reports/aie_top_all_mapping_analysis_report.txt

    # Extract numbers
    # IFS='x' read -r -a numbers <<< "${i##*_}"
    # num1="${numbers[0]}"
    # num2="${numbers[1]}"
    # num3="${numbers[2]}"

done
