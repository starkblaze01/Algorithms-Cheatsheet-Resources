#Calculating LCM (Least Common Multiple) by using GCD (Greatest Common Divisor):
## LCM(a,b) = abs(a*b) / GDC(a,b) - source: https://en.wikipedia.org/wiki/Least_common_multiple

def gcd(a, b):
    while b != 0:
        b, a = a % b, b
    return a

def lcm(a, b):
    return int(abs(a * b / gcd(a, b)))

if __name__ == "__main__":
    print("Least Common Multiple of 6 and 14 is " + str(lcm(6, 14)))
