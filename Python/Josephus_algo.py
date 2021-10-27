def josephus(n, k):
      if (n == 1):
          return 0
      else:
          return (josephus(n - 1, k) + k-1) % n 
# Driver Program to test above function
n = 14
k = 2
print("The chosen place is ", josephus(n, k))
