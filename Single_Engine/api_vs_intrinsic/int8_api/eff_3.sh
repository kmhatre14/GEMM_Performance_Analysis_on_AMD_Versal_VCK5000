#!/bin/bash

# Set the input log file path
input_log="search_results.log"

# Set the output log file path
output_log="extracted_data_log.txt"

# Set the path to the output log file for sorted data
sorted_output_log="sorted_extracted_data_log.txt"

# Define the regular expressions to extract directory names and lines containing only numbers
directory_regex="Directory: (.*)"
numbers_regex="\b[0-9]+\b"

# Function to extract lines containing only numbers along with their corresponding directory names, add serial numbers, and print them to a log file
extract_add_serial_and_print_to_log() {
    local serial_number=1
    local current_directory=""
    while IFS= read -r line; do
        if [[ $line =~ $directory_regex ]]; then
            current_directory="${BASH_REMATCH[1]}"
        fi
        if [[ $line =~ $numbers_regex ]]; then
            echo "$serial_number $current_directory $line" >> "$output_log"
            ((serial_number++))
        fi
    done < "$input_log"
}

# Call the function to extract data, add serial numbers, and print to the output log file
extract_add_serial_and_print_to_log

# Set the path to the input file
input_file="$output_log"

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

# Sort the extracted data based on the 5th field
sort -t ',' -k1,1n "$output_log" > "$sorted_output_log"
