def makeChange(d,w,n):
    d.append(0)
    d.sort()
    ans=[0]*(w+1)
    result=[]
    s=[0]*(w+1)
    for i in range(1,w+1):
        minimum=9999
        coin=0
        for j in range(1,n+1):
            if(i>=d[j]):
                minimum=min(minimum,1+ans[i-d[j]])
                coin=j
        ans[i]=minimum
        s[i]=coin
    l=w
    while(l>0):
        result.append(d[s[l]])
        l-=d[s[l]]
    print(result)

d=list(map(int,input("Enter Denomination :- ").split()))
w=int(input("Value :- "))
n=len(d)
makeChange(d,w,n)