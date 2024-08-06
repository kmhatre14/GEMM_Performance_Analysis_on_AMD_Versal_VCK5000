#!/bin/bash

# Set the path to the input file
input_file="/home/local/ASURITE/vmulleti/Desktop/NCHARM/CHARM/int8/extracted_data_log.txt"

# Set the path to the output log file
output_file="eff_2_output.log"

# Function to process the input text
process_text() {
    while IFS= read -r line; do
        # Replace multiple spaces with a single space
        line=$(echo "$line" | tr -s ' ')
        
        # Replace tabs with commas
        line=$(echo "$line" | tr '\t' ',')

        # Replace underscores with commas
        line=$(echo "$line" | tr '_' ',')

        # Replace remaining spaces with commas
        line=$(echo "$line" | tr ' ' ',')

        # Convert to array
        IFS=',' read -r -a array <<< "$line"

        # Print the 5th and 7th strings
        echo "${array[5]}, ${array[7]}"
    done < "$input_file" >> "$output_file"
}

# Call the function to process the text
process_text
