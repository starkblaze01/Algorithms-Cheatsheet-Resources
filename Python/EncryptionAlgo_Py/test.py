import numpy as np
a=np.array([[4201,68,64],[0,4201,0],[0,0,4201]])
a=a%26
print(np.linalg.det(a))
print(a)
from sympy import Matrix
a=Matrix(a).inv_mod(26)
print(a)