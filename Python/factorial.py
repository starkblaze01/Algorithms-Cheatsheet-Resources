#Python Porgram to calculate factorial of a given number

def fac(n):
    if n==0:
        return 1
    elif n<0:
        return "Invalid! Enter a positive number."
    elif n>0:
        return n*fac(n-1)


if __name__=='__main__':
    inp = int(input('please enter positive number (1-9999) : '))
    print(fac(inp))