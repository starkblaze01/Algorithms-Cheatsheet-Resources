# Importing needful libraries
import numpy as np

# A function to evaluate Q & R for a given array
def qr(A):
    m, n = A.shape
    Q = np.eye(m)
    for i in range(n - (m == n)):
        H = np.eye(m)
        # Computing matrix Hi
        H[i:, i:] = make_householder(A[i:, i])
        # Finding orthogonal matrix
        Q = np.dot(Q, H)
        # Find new matrix A using Hi
        A = np.dot(H, A)
    return Q, A

def make_householder(a):
    v = a / (a[0] + np.copysign(np.linalg.norm(a), a[0]))
    v[0] = 1
    H = np.eye(a.shape[0])
    H -= (2 / np.dot(v, v)) * np.dot(v[:, None], v[None, :])
    return H

def main():
    # Taking in the number of rows
    m = int(input('\n Please enter the number of rows - '))

    # Taking in the number of columns
    n = int(input('\n Please enter the number of columns - '))

    if m < n:
    	print('\nNumber of rows should be greater than or equal to number of columns')
    	return
    # Creating a matrix of random values with dimensions m,n
    a = np.random.rand(m, n)
    print('\n Original Matrix\n', a)   # Printing original matrix
    q, r = qr(a)    # Evaluating Q and R
    print('\n Q:\n', q.round(6))     # Printing Q
    print('\n R:\n', r.round(6))   # Printing R

    # print(np.matmul(q,r))    #Sample print of multiplication of q,r to check the correctness


if __name__ == '__main__':
    main()
