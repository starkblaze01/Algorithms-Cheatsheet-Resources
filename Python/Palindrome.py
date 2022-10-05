#Python program to check if a number is palindrome or not

def ispal(n):
    if n>0:
        return str(n)==str(n)[::-1]   #Converting the integer to string and reversing it to compare the two and check if they are equal.
    elif n<0:
        n=n*(-1)   #removing the negative sign because if we convert a negative number to string and reverse it then the negative sign will go at the back and will cause false results.
        return str(n)==str(n)[::-1]


if __name__=='__main__':
    print(ispal(1234321))
    print(ispal(-12321))
    print(ispal(1234))
    print(ispal(-1232))
