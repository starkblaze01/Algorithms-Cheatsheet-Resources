#Python Porgram to calculate factorial of a given number

def fac(n):
    if n==0:
        return 1
    elif n<0:
        return "Invalid! Enter a positive number."
    elif n>0:
        return n*fac(n-1)

