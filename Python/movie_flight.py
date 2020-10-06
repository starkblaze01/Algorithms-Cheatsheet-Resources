"""
Write a function that takes an integer flight_length (in minutes) and a list of integers movie_lengths (in minutes) and
returns a boolean indicating whether there are two numbers in movie_lengths whose sum equals flight_length.
"""

def can_two_movies_fill_flight(movie_lengths, flight_length):
	# Movie lengths we've seen so far
	movie_lengths_seen = set()
	
	for first_movie_length in movie_lengths:
		matching_second_movie_length = flight_length - first_movie_length
		if matching_second_movie_length in movie_lengths_seen:
			return True
		movie_lengths_seen.add(first_movie_length)
	
	# We never found a match, so return False
	return False

# O(n) time, and O(n) space. Note while optimizing runtime we added a bit of space cost.


"""
You are on a flight and wanna watch two movies during this flight.
You are given List<Integer> movieDurations which includes all the movie durations.
You are also given the duration of the flight which is d in minutes.
Now, you need to pick two movies and the total duration of the two movies is less than or equal to (d - 30min).

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

arr = [90, 85, 75, 60, 120, 150, 125]
k = 250
print(flightDetails(arr,k))
