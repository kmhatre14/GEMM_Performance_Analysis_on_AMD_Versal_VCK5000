source /mnt/vault1/kmhatre/Software/AMD/Vitis/2022.2/settings64.sh
export XILINX_VERSAL=/opt/AMD/common_files/xilinx-versal-common-v2022.2/
source $XILINX_VERSAL/environment-setup-cortexa72-cortexa53-xilinx-linux

export ROOTFS=/opt/AMD/common_files/xilinx-versal-common-v2022.2/rootfs.ext4  
export IMAGE=/opt/AMD/common_files/xilinx-versal-common-v2022.2/Image
export PLATFORM_REPO_PATHS=/mnt/vault1/kmhatre/Software/AMD/Vitis/2022.2/base_platforms/


echo ""
echo "Aiecompiler:"
which aiecompiler

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

