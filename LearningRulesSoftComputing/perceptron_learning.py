import math

 
def sgn(x):
    return 1 if x>0 else -1
 
def add(a, b):
    return [round(ai+bi, 2) for ai, bi in zip(a, b)]
 
def var_mul(x, a):
    return [round(x*ai, 2) for ai in a]
 
def mult(a, b):
    return sum([ai*bi for ai, bi in zip(a, b)])
 
if __name__ == '__main__':
    c = 0.1
    n = int(input('Enter no of input:'))
    x, d = [],[]
    for i in range(n):
        xi = list(map(float, input(f'Enter x{i}: ').strip().split(' ')))
        di = int(input('Enter desired output:'))
        x.append(xi); d.append(di)
      
    w = list(map(float, input('Enter initial weights:').split(' ')))
 
  
    for xi, di in zip(x, d):
        net = mult(xi, w)
        if(sgn(net) != sgn(di)):
            print("Correction Needed...")
            w = add(w, var_mul(c*(di - sgn(net)), xi))
            print("X: ", xi)
            print(f"W: {w}\n")
        else:
            print("Correction Not Needed..")
            print("X: ", xi)
            print(f"W: {w}\n")
            continue