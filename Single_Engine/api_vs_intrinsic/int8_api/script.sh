#!/bin/bash

# Original folder
orig_folder="aie_int8_new_128x128x128"

# Array of parameter values
L0_h1_values=(32 64 8 8 8 8 8 8 16 16 16 16 16 16 16 16 16 16 32 32 32 32 32 32 32 64 64 64 64 64 64 64 128 128 128 128 160)
L0_w1_values=(32 64 32 32 64 64 128 128 64 128 32 16 16 32 16 64 16 128 8 16 32 32 32 64 64 8 16 32 64 64 64 64 8 16 128 128 128)
L0_w2_values=(32 64 8 32 8 64 8 128 16 16 16 16 16 32 16 64 16 128 32 32 8 16 32 32 64 64 64 64 8 16 32 64 128 128 8 16 128)

# Loop to create copies
for i in ${!L0_h1_values[*]}
do
    # Get the new folder name from the parameter values
    new_folder="aie_int8_new${L0_h1_values[i]}x${L0_w1_values[i]}x${L0_w2_values[i]}"

    # Copy the original folder to the new folder
    cp -r "${orig_folder}" "${new_folder}"

    # Get the parameter values from the arrays
    h1=${L0_h1_values[i]}
    w1=${L0_w1_values[i]}
    w2=${L0_w2_values[i]}

    # Replace the values in the file
    sed -i "s/const int L0_h1=128;/const int L0_h1=${h1};/g" "${new_folder}/layer0/para_L0.h"
    sed -i "s/const int L0_w1=128;/const int L0_w1=${w1};/g" "${new_folder}/layer0/para_L0.h"
    sed -i "s/const int L0_w2=128;/const int L0_w2=${w2};/g" "${new_folder}/layer0/para_L0.h"
done
