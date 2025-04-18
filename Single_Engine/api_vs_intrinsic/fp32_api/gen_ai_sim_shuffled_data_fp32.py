import os  
import sys
import numpy as np
import random

M = int(sys.argv[1])
K = int(sys.argv[2])
N = int(sys.argv[3])

# Tile sizes
tileM=2
tileK=4
tileN=4

# Generate mtx A
A = []
for i in range(0,M):
    row = []
    for j in range(0,K):
        random.seed(i*j)
        row.append(float(random.randint(0,K)))
    A.append(row)
mtxA = np.matrix(A)

mtxAShuffled = []
for i in range(0,int(M/tileM)):
    for j in range(0,int(K/tileK)):
        for a in range(0,tileM):
            for b in range(0,tileK):
                mtxAShuffled.append(mtxA[i*tileM+a, j*tileK+b])

# Generate mtx B
B = []
for i in range(0,K):
    row = []
    for j in range(0,N):
        random.seed(i*j)
        row.append(float(random.randint(0,N)))
    B.append(row)
mtxB = np.matrix(B)

mtxBShuffled = []
for i in range(0,int(K/tileK)):
    for j in range(0,int(N/tileN)):
        for a in range(0,tileK):
            for b in range(0,tileN):
                mtxBShuffled.append(mtxB[i*tileK+a, j*tileN+b])

# Generate mtx C to write to an goldent_output file
mtxC=np.matmul(mtxA,mtxB)

mtxCShuffled = []
for i in range(0,int(M/tileM)):
    for j in range(0,int(N/tileN)):
        for a in range(0,tileM):
            for b in range(0,tileN):
                mtxCShuffled.append(mtxC[i*tileM+a, j*tileN+b])

# Write mtx A to text file
f = open("input0_unshuffled.txt", "w")
f.write("2415853568 ") 
counter = 1
for i in range(0,M):
    for j in range(0,K):
        if i == M-1 and j == K-1:
            break
        f.write(str(mtxA[i, j]))
        counter = counter + 1
        if counter == 4:
            f.write('\n')
            counter = 0
        else:
            f.write(' ')
f.write("TLAST\n")
f.write(str(mtxA[M-1, K-1]))
f.close()

f = open("input0.txt", "w")
for i in range(0,int(M*K/4)):
    if i == 0:
        f.write("2415853568 " + str(mtxAShuffled[0]) + ' ' + str(mtxAShuffled[1]) + ' ' + str(mtxAShuffled[2]) +'\n')
    else:
        f.write(str(mtxAShuffled[i*4-1]) + ' ' + str(mtxAShuffled[i*4]) + ' ' + str(mtxAShuffled[i*4+1]) + ' ' + str(mtxAShuffled[i*4+2])+'\n')
f.write("TLAST\n")
f.write(str(mtxAShuffled[M*K-1]))
f.close()

# Write mtx B to text file
f = open("input1_unshuffled.txt", "w")
f.write("2415853568 ") 
counter = 1
for i in range(0,K):
    for j in range(0,N):
        if i == K-1 and j == N-1:
            break
        f.write(str(mtxB[i, j]))
        counter = counter + 1
        if counter == 4:
            f.write('\n')
            counter = 0
        else:
            f.write(' ')
f.write("TLAST\n")
f.write(str(mtxB[K-1, N-1]))
f.close()

f = open("input1.txt", "w")
for i in range(0,int(K*N/4)):
    if i == 0:
        f.write("2415853568 " + str(mtxBShuffled[0]) + ' ' + str(mtxBShuffled[1]) + ' ' + str(mtxBShuffled[2]) +'\n')
    else:
        f.write(str(mtxBShuffled[i*4-1]) + ' ' + str(mtxBShuffled[i*4]) + ' ' + str(mtxBShuffled[i*4+1]) + ' ' + str(mtxBShuffled[i*4+2])+'\n')
f.write("TLAST\n")
f.write(str(mtxBShuffled[K*N-1]))
f.close()

f = open("golden_output_unshuffled.txt", "w")
counter = 0
f.write("\n") 
for i in range(0,M):
    for j in range(0,N):
        if i == M-1 and j == N-4:
            break
        f.write(str(mtxC[i, j]))
        counter = counter + 1
        if counter == 4:
            f.write('\n\n')
            counter = 0
        else:
            f.write(' ')
f.write("TLAST\n")
f.write(str(mtxC[M-1, N-4]) + ' ' + str(mtxC[M-1, N-3]) + ' ' + str(mtxC[M-1, N-2]) + ' ' + str(mtxC[M-1, N-1]))
f.close()

f = open("golden_output.txt", "w")
for i in range(0,int(M*N/4)-1):
    f.write('\n')
    f.write(str(mtxCShuffled[i*4]) + ' ' + str(mtxCShuffled[i*4+1]) + ' ' + str(mtxCShuffled[i*4+2]) + ' ' + str(mtxCShuffled[i*4+3])+'\n')
f.write("\nTLAST\n")
f.write(str(mtxCShuffled[M*N-4]) + ' ' + str(mtxCShuffled[M*N-3]) + ' ' + str(mtxCShuffled[M*N-2]) + ' ' + str(mtxCShuffled[M*N-1])+'\n')
f.close()
