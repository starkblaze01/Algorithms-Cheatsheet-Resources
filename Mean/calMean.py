def calMean(array):
	mean = 0
	for i in range(len(array)):
		mean = mean + array[i]
	mean = mean/float(len(array))
	return mean

if __name__ == "__main__": 
	array = [1,2,3,4]
	mean = calMean(array)
	print (mean)
