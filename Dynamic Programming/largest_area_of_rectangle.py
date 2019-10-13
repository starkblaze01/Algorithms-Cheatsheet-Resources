#A is a list of list of integers
def solve( A):
  x = len(A)
  y = len(A[0])
  for j in range(y):
      count = 0
      for i in range(x):
          if A[i][j]==1:
              count = count + 1       # Number of 1s in row
          else:
              count = 0               # If 0
          A[i][j] = count             # Setting Matrix entry with the count of 1s
  for k in range(x):
      A[k].sort(reverse=True)         # Descending order arrangement of 1s count
  size = 0
  for i in range(x-1, -1, -1):
      for j in range(y-1, -1, -1):
          mult1 = A[i][j]
          mult2 = j + 1
          size = max(size, mult1 * mult2) # Maximum Size by finding length*breadth
  return size # Size denotes the Maximum Size of the rectangle with 1s
