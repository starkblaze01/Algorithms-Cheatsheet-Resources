# Algorithm to check if a number is prime or not

num = 331
print("Is " + str(num) + " a prime number?")

prime = True
if num > 1:
    for i in range(2, num):
        if (num % i) == 0:
            prime = False
            break
    print(prime)
elif num == 1:
    print("1 is neither a prime nor a composite")
else:
    print("Give me natural number.")
