# Knapsack DP Problem 
# A Dynamic Programming approach
# KnapSack is a type of bag
# It basically returns the maximum value that can be put in a knapsack of capacity 'c'

def knapSack(c, weight, value, n): 
	K = [[0 for x in range(c + 1)] for x in range(n + 1)] 

	# Build table K[][] in bottom up manner 
	for i in range(n + 1): 
		for w in range(c + 1): 
			if i == 0 or w == 0: 
				K[i][w] = 0
			elif weight[i-1] <= w: 
				K[i][w] = max(value[i-1] + K[i-1][w-weight[i-1]], K[i-1][w]) 
			else: 
				K[i][w] = K[i-1][w] 

	return K[n][c] 

if __name__ == '__main__':

# values of 'n' items
	val = [70, 90, 150]

# weights of those 'n' items
	wt = [15, 25, 35]

# capacity of the knapsack
	c = 30
	n = len(val)
	print( knapSack(c, wt, val, n) )
