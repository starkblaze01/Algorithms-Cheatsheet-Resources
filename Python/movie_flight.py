"""
You are on a flight and wanna watch two movies during this flight.
You are given List<Integer> movieDurations which includes all the movie durations.
You are also given the duration of the flight which is k in minutes.
Now, you need to pick two movies and the total duration of the two movies is less than or equal to (k - 30min).

Find the pair of movies with the longest total duration and return they indexes. If multiple found, return the pair with the longest movie.
"""
def flightDetails(arr, k):
	k-=30
	arr = sorted(arr)
	left = 0
	right = len(arr)-1
	max_val = 0
	while left<right:
		if arr[left]+arr[right]<=k:
			if max_val < arr[left]+arr[right]:
				max_val = arr[left]+arr[right]
				i = left
				j = right
			left+=1
		else:
			right-=1
	return(arr[i],arr[j])


if __name__ == '__main__':
	arr = [90, 85, 75, 60, 120, 150, 125]
	k = 250
	print(flightDetails(arr,k))
