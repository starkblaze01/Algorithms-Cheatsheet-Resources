import math
def fi(n):
	p=(1+math.sqrt(5))
	p=p/2
	return (p**n)/math.sqrt(5)
n=int(input())
print(int(round(fi(n))))
