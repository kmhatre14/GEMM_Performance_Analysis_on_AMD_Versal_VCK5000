# Script to run


# Function to display usage
usage() {
    echo "Usage: ./run_exp.sh <output dir location> <# of interations> <Wokload List>"
    echo "                                 Workload List :- square | fat_skinny | charm "
}

if [ -z "$1" ] || [ -z "$2" ] || [ -z "$3" ]; then
    echo "Error: Please run the script with right inputs ."
    usage
fi



exe_dir=$1
iteration=$2
workload_list=$3

square=(
    '16,16,16'
    '32,32,32'
    '64,64,64'
    '128,128,128'
    '256,256,256'
    '512,512,512'
    '1024,1024,1024'
    '2048,2048,2048'
    '4096,4096,4096'
)


fat_skinny=(
    '256,128,256'
    '128,256,128'
    '128,256,256'
    '256,256,128'
    '512,128,512'
    '128,512,128'
    '128,512,512'
    '512,512,128'
    '1024,128,1024'
    '128,1024,128'
    '128,1024,1024'
    '1024,1024,128'
    '2048,1024,2048'
    '1024,2048,1024'
    '1024,2048,2048'
    '2048,2048,1024'
    '4096,2048,4096'
    '2048,4096,2048'
    '2048,4096,4096'
    '4096,4096,2048'
)

charm=(
    '3072,1024,1024'
    '3072,4096,1024'
    '3072,1024,4096'
    '512,64,512'
    '512,512,64'
    '3072,3024,1024'
    '3072,1024,1024'
    '3072,1024,4096'
    '3072,4096,1024'
    '3072,1024,3048'
    '3072,2048,4096'
    '3072,4096,4096'
    '3072,4096,1024'
)


run_vck(){

    array=("$@")
    IFS=','
    echo "Source the XRT file " 
    source /opt/xilinx/xrt/setup.sh
    # echo "parameter $exe_dir $iteration $1"
    for j in "${array[@]}"
        do
        read -ra numbers <<< $j
        # echo ${numbers[1]}
        echo Running ${numbers[0]} "x" ${numbers[1]} "x" ${numbers[2]} with $iteration iterations
        set -x
        ./${exe_dir}/hostexe ./${exe_dir}/mm_hw.xclbin ${numbers[0]} ${numbers[1]} ${numbers[2]} $iteration 0
        sleep 5
        set +x
    done
}

# Perform actions based on the input string
case $workload_list in
    square)
        echo "Running square workload"
        run_vck ${square[@]}
        ;;
    fat_skinny)
        echo "Running fat and skinny workload"
        run_vck ${fat_skinny[@]}
        ;;
    charm)
        echo "Running CHARM paper workload"
        run_vck ${charm[@]}
        ;;
    help)
    usage
    ;;
    *)
        echo "Unknown input: $input"
        usage
        ;;
esac


