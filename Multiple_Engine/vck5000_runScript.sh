# Command to run the test script
# /nfs/shared/mlcluster_job_submission -f externalFPGA --cpu 32 --gpu 0 --mem 32 --u55 0 --vck 1 --time 1 -n testvck -s ./vck5000_runScript.sh 
source /opt/xilinx/xrt/setup.sh
# export XRT_INI_PATH=./xrt.ini
# ./output/hostexe ./output/mm_hw.xclbin 4096 4096 4096 1000 0
# ./fp32/AIE16/output/hostexe ./fp32/AIE16/output/mm_hw.xclbin 32 128 128 1000 0

# ./run_exp.sh fp32/AIE16/output/ 10 new_asymetric &> new_asymetric.fp32.AIE16.vck5000.run

./run_exp.sh fp32/AIE384/output/ 1000 square &> square.fp32.AIE384.vck5000.run
./run_exp.sh fp32/AIE384/output/ 1000 fat_skinny &> fat_skinny.fp32.AIE384.vck5000.run
./run_exp.sh fp32/AIE384/output/ 1000 charm &> charm.fp32.AIE384.vck5000.run
./run_exp.sh fp32/AIE384/output/ 10 new_asymetric &> new_asymetric.fp32.AIE384.vck5000.run

# /nfs/shared/mlcluster_job_submission -f externalInteractive --cpu 4 --gpu 0 --mem 32 --u55 0 --vck 1 --time 2 -n testvc