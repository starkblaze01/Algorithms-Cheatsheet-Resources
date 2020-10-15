import sys 

def max(a, b): 
	return a if (a > b) else b 
	
def cutRod(price, n): 
	if(n <= 0): 
		return 0
	max_val = -sys.maxsize-1
	
	for i in range(0, n): 
		max_val = max(max_val, price[i] + cutRod(price, n - i - 1)) 
	return max_val 


arr = list(map(int , input().split()))
size = len(arr) 
print("Maximum Value that can be obtained is", cutRod(arr, size)) 

# By Jay Dulera
