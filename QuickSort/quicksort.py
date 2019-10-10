def quicksort(a, beg, end):
   if beg < end:
     split = partition(a, beg, end)
     quicksort(a, beg, split-1)
     quicksort(a, split+1, end)

def partition(a, beg, end):
    left = beg
    right = end
    pivot = left
    done = True
    while done:
        while a[pivot] <= a[right] and pivot != right:
            right = right - 1
        if pivot == right:
           done = False
        elif a[pivot] > a[right] :
           temp = a[right]
           a[right] = a[pivot]
           a[pivot] = a[temp]
           pivot = right 

        while a[pivot] >= a[left] and pivot != left:
            left = left + 1
        if pivot == left:
            done = False
        elif a[pivot] < a[left] :
           temp = a[left]
           a[left] = a[pivot]
           a[pivot] = temp
           pivot = left
    return pivot             

a = [4, 5, 7, 3, 6, 22, 45, 82]
quicksort(a, 0, len(a)-1)
print(a)