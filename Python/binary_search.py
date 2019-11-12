#return the index of a certain number in a sorted array.

def find_number(arr, num):

    left = 0
    right = len(arr)-1

    while right >= left:
        mid = (right+left)//2

        if arr[mid] == num:
            return mid
        elif arr[mid] > num:
            right = mid-1
        elif arr[mid] < num:
            left = mid+1

if __name__ == "__main__":

    array = [1,6,8,12,15,20,25,32,64]
    number = 20

    print(find_number(array, number))#print 5 (index)
