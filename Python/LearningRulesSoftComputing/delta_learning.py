from math import exp
 
 
def mul(l1, l2):
    return round(sum(a*b for a,b in zip(l1, l2)), 3)
 
def sgn(x):
    return 1 if x > 0 else -1
def imul(x, a):
    return [round(a*xi,3) for xi in x]
def add(l1, l2):
    return [round(a+b,3) for a,b in zip(l1, l2)]
def func(net):
    # bipolar continuous
    return 2 / (1 + exp(-net)) - 1
def funcdash(o):
    return (1 - o*o)/2
 
if __name__ == '__main__':
    c = 0.1
    n = int(input('Enter no of input:'))
    xn, dn = [], []
    for i in range(n):
        xi = list(map(float, input(f'Enter x{i}: ').strip().split(' ')))
        di = int(input('Enter desired output:'))
        xn.append(xi); dn.append(di)
    w = list(map(float, input('Enter initial weights:').split(' ')))
    for xi, di in zip(xn, dn):
        # print(f'Input: {xi}')
        net = mul(w, xi)
        # print(f'Expected output: {di}, Actual output: {net}')

        oi = round(func(net), 3)
        fnetdash = round(funcdash(oi), 3)
        print(f'oi = {oi}, fnetdash = {fnetdash}')

        xi = imul(xi, c * (di - oi) * fnetdash)
        w = add(w, xi)
        print(f'Updated weight: {w}')
