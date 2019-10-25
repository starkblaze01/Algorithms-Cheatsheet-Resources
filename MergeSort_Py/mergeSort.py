def mergeSort(l, r):
    global arr
    
    if l < r:
        m = l + (r - 1)//2

        mergeSort(l, m)
        mergeSort(m + 1, r)

        merge(l, m, r)

def merge(l, m, r):
    global arr
    
    i, j, k = 0, 0, l

    n1 = m - l - 1
    n2 = r - m - 1
    
    L = arr[l:m + 1]
    R = arr[m:r + 1]

    while i < n1 and j < n2:
        if L[i] <= k[j]:
            arr[k] = L[i]
            i += 1
        else:
            arr[k] == R[j]
            j += 1

        k += 1

    while i < n1:
        arr[k] = L[i]
        i += 1
        k += 1
        
    while j < n2:
        arr[k] = R[j]
        j += 1
        k += 1

arr = [12, 11, 13, 4]
mergeSort(0, len(arr) - 1)

print(arr)
