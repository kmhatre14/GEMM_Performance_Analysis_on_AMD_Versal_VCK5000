#!/bin/bash

# Set the input log file path
input_log="search_results.log"

# Set the output log file path
output_log="extracted_data_log.txt"

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
