# Python3 program for the above approach
def Solution(arr):

	n = len(arr)

	# If length of array is even
	if n % 2 == 0:
		z = n // 2
		e = arr[z]
		q = arr[z - 1]
		ans = (e + q) / 2
		return ans
		
	# If length of array is odd
	else:
		z = n // 2
		ans = arr[z]
		return ans

# Driver code
if __name__ == "__main__":
	
	arr1 = [ -5, 3, 6, 12, 15 ]
	arr2 = [ -12, -10, -6, -3, 4, 10 ]

	# Concatenating the two arrays
	arr3 = arr1 + arr2

	# Sorting the resultant array
	arr3.sort()

	print("Median = ", Solution(arr3))
