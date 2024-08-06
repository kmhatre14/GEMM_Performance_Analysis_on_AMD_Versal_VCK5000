#!/bin/bash

# Base directory containing the sim folders
base_dir="/mnt/vault0/vmulleti/Versal_Perf_Analysis/Versal_ACAP_Analysis/Single_Engine/int8/sim"

# Iterate over each .vcd file in the base directory and its subdirectories
find "$base_dir" -name "*.vcd" | while read -r vcd_file; 
do
    # Extract the directory containing the .vcd file
    vcd_dir=$(dirname "$vcd_file")
    
    # Extract the base name of the .vcd file without the directory path and extension
    base_name=$(basename "$vcd_file" .vcd)
    
    # Construct the corresponding pkg-dir path (assuming it follows a specific naming pattern)
    pkg_dir="${vcd_dir}/../../work_aie/Work_${base_name}"
    
    # Construct the path to the events.txt file (assuming it follows a specific naming pattern)
    events_file="${vcd_dir}/trdata.aiesim/events.txt"
    
    # Navigate to the directory containing the .vcd file
    cd "$vcd_dir" || exit
    
    # Run the vcdanalyze command with just the base name
    echo "Running vcdanalyze for $base_name.vcd with pkg-dir $pkg_dir"
    vcdanalyze --vcd "$base_name.vcd" --pkg-dir "$pkg_dir"
    
    # Run the parse_events.py script with the events.txt file as an argument
    if [ -f "$events_file" ]; then
        echo "Running parse_events.py with $events_file"
        python3 /mnt/vault0/vmulleti/Versal_Perf_Analysis/Versal_ACAP_Analysis/Scripts/parse_events.py "$events_file"
    else
        echo "Warning: events.txt file not found for $vcd_file"
    fi
done
