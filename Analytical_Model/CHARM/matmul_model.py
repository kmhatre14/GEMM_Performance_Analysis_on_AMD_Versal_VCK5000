import os
import sys
import subprocess
import numpy as np
cur_dir = os.path.dirname(os.path.abspath(__file__))
sys.path.append(os.path.dirname(cur_dir))
from cdse import cdse_top

#Set the design project path
# prj_dir= cur_dir + '/prj_try_exp'
# subprocess.run(['mkdir','-p' ,f'{prj_dir}'])

#Define the left-hand-side(A) and right-hide-side(B) operands
# MAT_DIM_MKN = (
#     [32,128,128],
#     [16,16,16],
#     [32,32,32],
#     [64,64,64],
#     [128,128,128],
#     [256,256,256],
#     [512,512,512],
#     [1024,1024,1024],
#     [2048,2048,2048],
#     [4096,4096,4096],
#     [256,128,256],
#     [128,256,128],
#     [128,256,256],
#     [256,256,128],
#     [512,128,512],
#     [128,512,128],
#     [128,512,512],
#     [512,512,128],
#     [1024,128,1024],
#     [128,1024,128],
#     [128,1024,1024],
#     [1024,1024,128],
#     [2048,1024,2048],
#     [1024,2048,1024],
#     [1024,2048,2048],
#     [2048,2048,1024],
#     [4096,2048,4096],
#     [2048,4096,2048],
#     [2048,4096,4096],
#     [4096,4096,2048],
#     [3072,1024,1024],
#     [3072,4096,1024],
#     [3072,1024,4096],
#     [512,64,512],
#     [512,512,64],
#     [3072,3024,1024],
#     [3072,1024,1024],
#     [3072,1024,4096],
#     [3072,4096,1024],
#     [3072,1024,3048],
#     [3072,2048,4096],
#     [3072,4096,4096],
#     [3072,4096,1024],
# )
MAT_DIM_MKN = (
    [1024,1024,1024],
)

for i in MAT_DIM_MKN:
    # print(i)
    
    A=np.random.rand(i[0], i[1]).astype(np.float32)
    B=np.random.rand(i[1], i[2]).astype(np.float32)
    config=[1,4,4,4,4,4,1]
    # #Create the object of the class charm
    final_config=cdse_top(A,B,config)

#Launch charm dse to find optimized hardware configuration
# Versal_config=automm.cdse(A,B)

#Launch charm automatic code generator to emit the code for AIE, PL and Host CPU
# device='vck5000' # Supported devices are vck190 and vck5000
# automm.cacg(Versal_config,device)

# #Run Vitis Compilation Flow
# automm.build()