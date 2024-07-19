# Vitis compilations
# list=(
#     'aie_fp32_32x32x32'
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
# list=(
# 'aie_int8_32x32x32'
# 'aie_int8_64x64x64'
# 'aie_int8_16x16x16'
# 'aie_int8_64x32x64'
# 'aie_int8_32x64x32'
# 'aie_int8_64x64x32'
# 'aie_int8_32x64x64'
# 'aie_int8_32x16x32'
# 'aie_int8_16x32x16'
# 'aie_int8_32x32x16'
# 'aie_int8_16x32x32'
# 'aie_int8_128x16x128'
# 'aie_int8_16x128x16'
# 'aie_int8_128x128x16'
# 'aie_int8_16x128x128'
# 'aie_int8_64x16x64'
# 'aie_int8_16x64x16'
# 'aie_int8_64x64x16'
# 'aie_int8_16x64x64'
# 'aie_int8_128x8x128'
# 'aie_int8_8x128x8'
# 'aie_int8_128x128x8'
# 'aie_int8_8x128x128'
# 'aie_int8_64x8x64'
# 'aie_int8_8x64x8'
# 'aie_int8_64x64x8'
# 'aie_int8_8x64x64'
# 'aie_int8_32x8x32'
# 'aie_int8_8x32x8'
# 'aie_int8_32x32x8'
# 'aie_int8_8x32x32'
# 'aie_int8_128x128x128'
# 'aie_int8_16x32x16'
# 'aie_int8_16x128x16'
# 'aie_int8_16x64x16'
# )


for i in "${list[@]}"
do
    echo "Running " "$i"
    rm -rf libadf.a
    make -f Makefile_VCK190 aie aie_kernel_config=$i &> aiecompile_$i.log
done
