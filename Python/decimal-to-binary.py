def binary(number):
	ans = ""
	while number:
		ans += str(number % 2)
		number //= 2
	print("The output of that number in base 2 is:", ans[::-1] if ans != "" else 0)
	
num = int(input("Enter any number with base 10: "))
binary(num)
