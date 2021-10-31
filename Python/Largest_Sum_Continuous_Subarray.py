def maxsumcontinuoussubarray(arr,n):
    sum=0
    res=0
    for i in range(len(arr)):
        if (sum+arr[i])<0:
            sum=0
        else:
            sum+=arr[i]
        res=max(res,sum)
    return res
            

n=int(input())
arr=list(map(int,input().split()))
print(maxsumcontinuoussubarray(arr,n))

#time complexity=O(n)
#space=O(1)
