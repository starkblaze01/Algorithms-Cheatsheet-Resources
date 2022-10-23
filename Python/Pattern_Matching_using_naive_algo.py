def pattern(text,pat):
    n=len(text)
    m=len(pat)
    c=0
    for i in range(n-m+1):
        j=0
        
        while(j<m):
            if text[i+j]!=pat[j]:
                break
            j+=1
            
        if j==m:
            c+=1
            #print each index of match
            print(i)
    #count no of match
    print(c)
        
text=input()
pat=input()
pattern(text,pat)
