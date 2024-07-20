# Vitis aie simulator
# list=(
# 'aie_fp32_32x32x32'
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
    echo "Generating data for $i"
    # Extract numbers
    IFS='x' read -r -a numbers <<< "${i##*_}"
    num1="${numbers[0]}"
    num2="${numbers[1]}"
    num3="${numbers[2]}"

    # echo "Number 1: $num1"
    # echo "Number 2: $num2"
    # echo "Number 3: $num3"

    #echo "Running aiesim" "$i"
    python3 gen_aie_sim_data_fp32.py $num1 $num2 $num3

    echo "Running aiesim" "$i"
    make -f Makefile_VCK190 aiesim aie_kernel_config=$i &> aiesim_$i.log
done
