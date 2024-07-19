#!/bin/bash

# Base directory containing the folders with 'summary' text files
BASE_DIR="/mnt/vault0/vmulleti/Versal_Perf_Analysis/Versal_ACAP_Analysis/Single_Engine/int8/sim"

# Output file to store the combined data
OUTPUT_FILE="$BASE_DIR/summary_output.txt"

# Empty the output file if it exists
> "$OUTPUT_FILE"

# Find all 'summary' files in the base directory and its subdirectories
find "$BASE_DIR" -type f -name "summary" | while read -r file; do
  # Extract the desired part of the directory name (last segment after the last underscore)
  dir_name=$(basename "$(dirname "$file")")
  extracted_part="${dir_name#*_}"
  
  # Write the extracted part to the output file
  echo "$extracted_part" >> "$OUTPUT_FILE"
  
  # Append the lines except the first one to the output file
  tail -n +1 "$file" >> "$OUTPUT_FILE"
  
  # Add a newline for separation
  echo "" >> "$OUTPUT_FILE"
  
  echo "Processed $file"
done

echo "All files have been processed. Combined data is saved in $OUTPUT_FILE."
