from math import sqrt

x1 = input("Please enter x coordinate for point 1: ")
y1 = input("Please enter y coordinate for point 1: ")
z1 = input("Please enter z coordinate for point 1: ")

x1, y1, z1 = int(x1), int(y1), int(z1)

x2 = input("Please enter x coordinate for point 2: ")
y2 = input("Please enter y coordinate for point 2: ")
z2 = input("Please enter z coordinate for point 2: ")

x2, y2, z2 = int(x2), int(y2), int(z2)

dx_2 = pow(x1-x2, 2)
dy_2 = pow(y1-y2, 2)
dz_2 = pow(z1 - z2, 2)

print(sqrt(dx_2+dy_2+dz_2))

