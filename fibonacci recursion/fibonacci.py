def iter(n, prev, curr):
    if n == 0:
        return curr
    return iter(n-1, curr, prev + curr)

def fibonacci(n):
    return iter(n, 1, 0)

if __name__ == '__main__':
    print(fibonacci(int(input())))