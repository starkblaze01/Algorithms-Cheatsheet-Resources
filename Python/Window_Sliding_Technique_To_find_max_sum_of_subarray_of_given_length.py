def maxsum(arr,n,k):
    if n<k:
        print("invalid")
        return -1
    window_sum=sum(arr[:k])
    print(window_sum)
    max_sum=window_sum
    for i in range(n-k):
        window_sum=window_sum-arr[i]+arr[i+k]
        print(window_sum)
        max_sum=max(max_sum,window_sum)
        
    return max_sum

n,k=map(int,input().split())
arr=list(map(int,input().split()))
print(maxsum(arr,n,k))
