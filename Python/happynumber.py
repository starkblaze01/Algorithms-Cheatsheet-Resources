def sq(n):
    a=0
    while n:   
        r=n%10
        a+=r**2
        n=n//10
    print(a)
def isHappy(n):
    while n:
        sq(n)
    
isHappy(19)
