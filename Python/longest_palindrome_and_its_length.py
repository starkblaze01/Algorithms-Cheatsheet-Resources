def longestpal(string):
    maxlen=1
    start=0
    n=len(string)
    low=0
    high=0
    for i in range(1,n):
        #evenlengthpalindrome
        low=i-1
        high=i
        while low>=0 and high<n and string[low]==string[high]:
            if high-low+1>maxlen:
                start=low
                maxlen=high-low+1
            low-=1
            high+=1
            
        #oddlengthpalindrome
        low=i-1
        high=i+1
        while low>=0 and high<n and string[low]==string[high]:
            if high-low+1>maxlen:
                start=low
                maxlen=high-low+1
            low-=1
            high+=1
    print(string[start:start + maxlen])
    print(maxlen)
    
    
string = input()
longestpal(string)
