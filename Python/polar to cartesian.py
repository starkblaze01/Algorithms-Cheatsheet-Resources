# polar to cartesian
from cmath import cos, sin, sqrt
from numpy import arctan


r = float(input("Enter r coordinate: "))
theta = float(input("Enter theta coordinate: "))


x = r * cos(theta)
y = r * sin(theta)

print("x is:", x)
print("y is: ", y)