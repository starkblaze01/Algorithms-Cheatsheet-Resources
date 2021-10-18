'''
There are some colored rabbits in a forest. Given an array arr[] 
of size N, such that arr[i] denotes the number of rabbits having 
same color as the ith rabbit, the task is to find the minimum number 
of rabbits that could be in the forest.
'''
import math
def rabbits(A):
    d={}
    for i in A:
        if i in d:
            d[i]+=1
        else:
            d[i]=1
    ans=0
    for i in d:
        gs=i+1
        reportees=d[i]
        ng=int(math.ceil(reportees*1.0/gs*1.0))
        ans+=ng*gs
    return ans
A=[10,10,10]
print(rabbits(A))

