def primesieve(a,n):
    global m
    N=n
    n+=5
    prime=[0 for i in range(n+1)]
    p=2
    while(p*p<=n):
        if(prime[p]==0):
            for i in range(p*p,n,p):
                prime[i]=1
        p+=1
    c=0
    for i in range(a,N+1):
        if prime[i]==0:
            m.append(i)
            c+=1
    return (m,c)
            


a,n=map(int,input().split())
m=[];c=0
print(primesieve(a,n))
