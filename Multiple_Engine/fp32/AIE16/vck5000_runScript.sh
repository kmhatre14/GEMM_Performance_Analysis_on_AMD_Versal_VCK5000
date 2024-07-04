# Command to run the test script
# /nfs/shared/mlcluster_job_submission -f externalFPGA --cpu 16 --gpu 0 --mem 32 --u55 0 --vck 1 --time 1 -n testvck -s ./vck5000_runScript.sh 
source /opt/xilinx/xrt/setup.sh
export XRT_INI_PATH=./xrt.ini
./output/hostexe ./output/mm_hw.xclbin 4096 4096 4096 1000 0
# /nfs/shared/mlcluster_job_submission -f externalInteractive --cpu 4 --gpu 0 --mem 32 --u55 0 --vck 1 --time 2 -n testvc