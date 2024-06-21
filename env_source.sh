#!/bin/bash

# Function to display usage
usage() {
    echo "Usage: $0 <Server_Name>"
    echo "Server_Name : hacc , advent"
    exit 1
}

# Load the Advent Sirius environment 
advent_env(){
    echo "Loading Advent Vitis Enviroment"

    source /mnt/vault1/kmhatre/Software/AMD/Vitis/2022.2/settings64.sh
    export XILINX_VERSAL=/opt/AMD/common_files/xilinx-versal-common-v2022.2/
    source $XILINX_VERSAL/environment-setup-cortexa72-cortexa53-xilinx-linux

    export ROOTFS=/opt/AMD/common_files/xilinx-versal-common-v2022.2/rootfs.ext4  
    export IMAGE=/opt/AMD/common_files/xilinx-versal-common-v2022.2/Image
    export PLATFORM_REPO_PATHS=/mnt/vault1/kmhatre/Software/AMD/Vitis/2022.2/base_platforms/

}

# Load the HACC environment 
hacc_env(){
    echo "Loading HACC Vitis Enviroment"
    source /tools/Xilinx/Vitis/2022.2/settings64.sh
    source /opt/xilinx/xrt/setup.sh
}

# Print the environment
print_env(){
    echo ""
    which aiecompiler

    echo "Aiecompiler:"
    echo ""
    echo "Vivado:"
    which vivado

    echo ""
    echo "Vitis:"
    which vitis

    echo ""
    echo "Vitis HLS:"
    which vitis_hls
    echo ""
}


# Check if any input is provided
if [ -z "$1" ]; then
    echo "Error: No input provided."
    usage
fi

# Get the input string
input=$1

# Perform actions based on the input string
case $input in
    hacc)
        echo "Loading environment variables for HACC"
        hacc_env
        print_env
        ;;
    advent)
        echo "Loading environment variables for Advent - Sirius"
        advent_env
        print_env
        ;;
    help)
        usage
        ;;
    *)
        echo "Unknown input: $input"
        echo "Try 'help'"
        ;;
esac