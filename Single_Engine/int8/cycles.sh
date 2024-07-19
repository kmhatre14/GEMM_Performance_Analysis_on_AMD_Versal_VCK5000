#!/bin/bash

# Set the directory where the text files are located
DIRECTORY="/mnt/vault0/vmulleti/Versal_Perf_Analysis/Versal_ACAP_Analysis/Single_Engine/int8"

# Find all subdirectories whose names start with "aie_sim_aie_int8_"
subdirs=$(find "$DIRECTORY" -type d -name 'aie_sim_aie_int8_*')

# Loop through each subdirectory
for subdir in $subdirs; do
    echo "Processing files in $subdir..."
    
    # Print the header
    echo "Calls  Cycles tot   Cycles tot  Cycles min  Cycles avg  Cycles max  Cycles tot   Cycles tot  Cycles min  Cycles avg  Cycles max     Low PC     High PC    Function"
    echo "       (func)      (%func)      (func)      (func)      (func) (func+desc) (%func+desc) (func+desc) (func+desc) (func+desc)"
    echo "----------- ----------- ------------ ----------- ----------- ----------- ----------- ------------ ----------- ----------- ----------- ---------- ---------- --------------------------------------------------"

    # Loop through each text file in the current subdirectory
    for file in "$subdir"/*.txt; do
        # Print the contents of the file, filtering for lines containing the specified pattern
        awk '/aie_sim_aie_int8/ {print}' "$file"
    done
    
    echo "--------------------------------------------------"
done
