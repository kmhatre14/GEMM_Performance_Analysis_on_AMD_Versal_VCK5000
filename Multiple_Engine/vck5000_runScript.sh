# Command to run the test script
# /nfs/shared/mlcluster_job_submission -f externalFPGA --cpu 32 --gpu 0 --mem 32 --u55 0 --vck 1 --time 1 -n testvck -s ./vck5000_runScript.sh 
source /opt/xilinx/xrt/setup.sh
# export XRT_INI_PATH=./xrt.ini
# ./output/hostexe ./output/mm_hw.xclbin 4096 4096 4096 1000 0
# ./fp32/AIE16/output/hostexe ./fp32/AIE16/output/mm_hw.xclbin 32 128 128 1000 0
# ./fp32/AIE32/output/hostexe ./fp32/AIE32/output/mm_hw.xclbin 64 128 128 1000 0
# ./fp32/AIE64/output/hostexe ./fp32/AIE64/output/mm_hw.xclbin 128 128 128 1000 0
# ./fp32/AIE128/output/hostexe ./fp32/AIE128/output/mm_hw.xclbin 128 256 128 1000 0
# ./fp32/AIE256/output/hostexe ./fp32/AIE256/output/mm_hw.xclbin 256 128 256 1000 0
# ./fp32/AIE384/output/hostexe ./fp32/AIE384/output/mm_hw.xclbin 384 128 256 1000 0

# ./int8/AIE16/output/hostexe ./int8/AIE16/output/mm_hw.xclbin 128 256 128 1000 0
# ./int8/AIE32/output/hostexe ./int8/AIE32/output/mm_hw.xclbin 128 256 256 1000 0
# ./int8/AIE64/output/hostexe ./int8/AIE64/output/mm_hw.xclbin 256 256 256 1000 0
# ./int8/AIE128/output/hostexe ./int8/AIE128/output/mm_hw.xclbin 256 512 256 1000 0
# ./int8/AIE256/output/hostexe ./int8/AIE256/output/mm_hw.xclbin 256 512 512 1000 0
# ./fp32/AIE16_isolated/AIE16_nocompute_noMMtypeKernel_noCascade/output/hostexe ./fp32/AIE16_isolated/AIE16_nocompute_noMMtypeKernel_noCascade/output/mm_hw.xclbin 32 128 128 1000 0 
# ./int8/AIE384/output/hostexe ./int8/AIE384/output/mm_hw.xclbin 512 512 512 1000 0
# ./run_exp.sh int8/AIE256/output 1000 square &> square.int8.AIE256.vck5000.run
# ./run_exp.sh int8/AIE256/output 1000 fat_skinny &> fat_skinny.int8.AIE256.vck5000.run
# ./run_exp.sh int8/AIE256/output 1000 charm &> charm.int8.AIE256.vck5000.run
# /nfs/shared/mlcluster_job_submission -f externalInteractive --cpu 4 --gpu 0 --mem 32 --u55 0 --vck 1 --time 2 -n testvc