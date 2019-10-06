def fib(n):
	if n < 2:
		return 1
	return n + fib(n - 1)