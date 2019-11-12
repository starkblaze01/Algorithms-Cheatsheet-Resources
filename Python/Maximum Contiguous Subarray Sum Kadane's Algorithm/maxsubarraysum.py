import sys
def maximumsum(a,n):
    max_so_far = -sys.maxsize
    max_till_here = 0
    n=len(a)
    for i in range(n):
        max_till_here+=a[i]
        if max_so_far<max_till_here:
            max_so_far=max_till_here
        if max_till_here<0:
            max_till_here=0
    return max_so_far

# TEST USING YOUR LIST OF ELEMENTS

l=[-13, -3, -25, -20, -3, -16, -23, -12, -5, -22, -15, -4, -7]
maxsum=maximumsum(l,len(l))
print(maxsum)

l=[1,2,3,4,5]
maxsum=maximumsum(l,len(l))
print(maxsum)