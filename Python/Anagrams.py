from collections import *
a=Counter(input())
b=Counter(input())
c=a-b
d=b-a
e=c+d
#print(a,b,c,d,e)
print(len(list(e.elements())))


or
import math

def number_needed(a, b):
    aString = [0]*26
    for ch in a:
        aString[ord(ch)-97] += 1
    
    bString = [0]*26
    for ch in b:
        bString[ord(ch)-97] += 1
        
    deletions = 0
    for i in range(len(aString)):
        deletions += math.fabs(aString[i]-bString[i])
    
    print(aString,bString,deletions)

a = input().strip()
b = input().strip()

print(number_needed(a, b))
