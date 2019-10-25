def HeapSort(arr):
    for i in range(len(arr), 1, -1):
        parent = arr[i//2 - 1]
        child = arr[i - 1]
        
        print('Parent of ' + str(child) + ' : ' + str(parent))

        if(parent < child):
            arr[i//2 - 1], arr[i - 1] = child, parent
    return arr

arr = [20,10,6,2,5,3,15]
print(HeapSort(arr))
