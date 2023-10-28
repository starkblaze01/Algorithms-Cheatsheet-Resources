# cartesian to polar
from cmath import sqrt
from numpy import arctan


x = input("Enter x coordinate: ")
y = input("Enter y coordinate: ")

z = int(y)/int(x)
theta = arctan([z])
r = sqrt(pow(int(x), 2) + pow(int(y), 2))

print("theta is:", theta, "rad")
print("r is: ", r)
