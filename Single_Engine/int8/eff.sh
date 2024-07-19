#!/bin/bash

# Define the pattern to search for in the text files
pattern="Cycle count details for function mm7_kernel0_L0 _Z14mm7_kernel0_L0P12input_windowIaES1_P13output_windowIaE"

# Directory where you want to start the search
search_dir="/mnt/vault0/vmulleti/Versal_Perf_Analysis/Versal_ACAP_Analysis/Single_Engine/int8/sim"

# Log file to store the output
log_file="search_results.log"

# Clear the log file before writing new content
> "$log_file"

# Search for directories containing "aie_sim_aie_int8_" in their names
# Then search for text files starting with "profile_instr_23_" in those directories and print lines containing the pattern
find "$search_dir" -type d -name "*aie_sim_aie_int8_*" | while IFS= read -r directory; do
    dir_name=$(basename "$directory")
    echo "Directory: $dir_name" >> "$log_file"
    echo "-------------------------" >> "$log_file"
    
    # Search for all text files in the directory matching the specified pattern
    found=false
    find "$directory" -type f -name "profile_funct_*.txt" | while IFS= read -r file; do
        # Search for the pattern in the file and print the matching lines
        if grep -q "$pattern" "$file"; then
            file_name=$(basename "$file")
            echo "File: $file_name" >> "$log_file"
            echo "-------------------------" >> "$log_file"
            grep -A 5 "$pattern" "$file" >> "$log_file"
            found=true
        fi
    done

    if ! $found; then
        echo "No matching lines found in any text file in directory: $dir_name" >> "$log_file"
    fi
    
    echo >> "$log_file"
done

echo "Search results have been saved to: $log_file"
