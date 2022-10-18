import re

Input = input("Please enter an email: ")


x = re.search("[a-zA-Z0-9]+@[a-zA-Z0-9]+\.[a-zA-Z0-9]+", Input)
if x == None:
    print("This is not a valid email format")
else:
    print("This is a valid email format")
