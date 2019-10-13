def adjacent( A):
        if(len(A[0])==1):
            return max(A[0][-1],A[1][-1])
        n=len(A[0])
        arr=[0 for i in range(n)]
        arr[-1]=max(A[0][-1],A[1][-1])
        arr[-2]=max(A[0][-2],A[1][-2],arr[-1])
        for i in range(n-3,-1,-1):
            val=0
            temp=max(A[0][i],A[1][i])
            arr[i]=max(temp+arr[i+2],arr[i+1])
        return arr[0]
