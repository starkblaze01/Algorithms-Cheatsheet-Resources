def insSort(arr):
    for j in range(1, len(arr)):
        key = arr[j]
        i = j - 1

        while(i >= 0 and arr[i] > key):
            arr[i + 1] = arr[i]
            i -= 1
        arr[i + 1] = key   
        print(arr)

    return arr

def selSort(arr):
    for i in range(len(arr) - 1):
        minNum = arr[i]
        loc = i

        for j in range(i + 1, len(arr)):
            if(minNum > arr[j]):
                minNum = arr[j]
                loc = j

        arr[i], arr[loc] = arr[loc], arr[i]
        print(arr)

    return arr

arr = [2,4,1,9,3,5,7,6]
selSort(arr)
