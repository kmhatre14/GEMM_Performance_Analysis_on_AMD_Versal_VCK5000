import os  
import sys

M = int(sys.argv[1])
K = int(sys.argv[2])
N = int(sys.argv[3])


f = open("data/input0.txt", "w")
for j in range(0,4):

    for i in range(0,int(M*K/16)):
        if i == 0:
            f.write("2415853568 " + str(1) + ' ' + str(1) + ' ' + str(1)+' '+ str(1)+' '+ str(1) + ' ' + str(1) + ' ' + str(1)+' '+ str(1)+ ' ' + str(1) + ' ' + str(1)+' '+ str(1)+' '+ str(1) + ' ' + str(1) + ' ' + str(1)+' '+ str(1) +'\n')
        else:
            f.write(str(1) + ' ' + str(1) + ' ' + str(1) + ' ' + str(1)+' '+ str(1)+' '+ str(1) + ' ' + str(1) + ' ' + str(1)+' '+ str(1)+ ' ' + str(1) + ' ' + str(1)+' '+ str(1)+' '+ str(1) + ' ' + str(1) + ' ' + str(1)+' '+ str(1) +'\n')

    f.write("TLAST\n")
    f.write(str(1) + ' ' + str(1) + ' ' + str(1) + ' ' + str(1)+' '+ str(1)+' '+ str(1) + ' ' + str(1) + ' ' + str(1)+' '+ str(1)+ ' ' + str(1) + ' ' + str(1)+' '+ str(1)+' '+ str(1) + ' ' + str(1) + ' ' + str(1)+' '+ str(1) +'\n')
f.close()

f = open("data/input1.txt", "w")
for j in range(0,4):

    for i in range(0,int(K*N/16)):
        if i == 0:
            f.write("2415853568 " + str(1) + ' ' + str(1) + ' ' + str(1)+' '+ str(1)+' '+ str(1) + ' ' + str(1) + ' ' + str(1)+' '+ str(1)+ ' ' + str(1) + ' ' + str(1)+' '+ str(1)+' '+ str(1) + ' ' + str(1) + ' ' + str(1)+' '+ str(1) +'\n')
        else:
            f.write(str(1) + ' ' + str(1) + ' ' + str(1) + ' ' + str(1)+' '+ str(1)+' '+ str(1) + ' ' + str(1) + ' ' + str(1)+' '+ str(1)+ ' ' + str(1) + ' ' + str(1)+' '+ str(1)+' '+ str(1) + ' ' + str(1) + ' ' + str(1)+' '+ str(1) +'\n')

    f.write("TLAST\n")
    f.write(str(1) + ' ' + str(1) + ' ' + str(1) + ' ' + str(1)+' '+ str(1)+' '+ str(1) + ' ' + str(1) + ' ' + str(1)+' '+ str(1)+ ' ' + str(1) + ' ' + str(1)+' '+ str(1)+' '+ str(1) + ' ' + str(1) + ' ' + str(1)+' '+ str(1) +'\n')
f.close()