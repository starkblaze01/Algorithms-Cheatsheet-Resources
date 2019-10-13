def longestSubsequenceLength( A):
        n=len(A)
        inc=[1]*n
        for i in range(1,n):
            for j in range(0,i):
                if A[i]>A[j] and inc[j]+1>inc[i]:
                    inc[i]=inc[j]+1
                    
        dec=[1]*n
        for i in range(n-2,-1,-1):
            for j in range(i+1,n):
                if A[i]>A[j] and dec[j]+1>dec[i]:
                    dec[i]=dec[j]+1
        maximum=1
        for x,y in zip(inc,dec):
            maximum=max(maximum,x+y)
        return maximum-1
