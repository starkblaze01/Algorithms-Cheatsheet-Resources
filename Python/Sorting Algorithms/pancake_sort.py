#pancake sort implementation in python

def flip(arr, i):
    start = 0
    while start < i:
        temp = arr[start]
        arr[start] = arr[i]
        arr[i] = temp
        start += 1
        i -= 1

def findMax(arr, n):
    maxi = 0
    for i in range(0,n):
        if arr[i] > arr[maxi]:
            maxi = i
    return maxi

def pancake_sort(arr, n):
    c = n
    while c > 1:
        maxi = findMax(arr, c)
        if maxi != c-1:
            flip(arr, maxi)
            flip(arr, c-1)
        c = c-1
 

if __name__=="__main__":
    arr=[5,4,9,7,3,1]
    print("Unsorted Array : ",end="")
    print(arr)
    pancake_sort(arr,len(arr))
    print("Sorted Array : ",end="")
    print(arr)
