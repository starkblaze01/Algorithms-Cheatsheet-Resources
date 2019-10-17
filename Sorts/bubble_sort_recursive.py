# Script: bubble_sort_recursive.py
# Author: Joseph L. Crandal
# Purpose: Demonstrate bubble sort with recursion

# data will be the list to be sorted
data = [ 0, 5, 2, 3, 10, 123, -53, 23, 9, 2 ]
dataOrig = [ 0, 5, 2, 3, 10, 123, -53, 23, 9, 2 ]

# In a bubble sort you will work your way through the dataset
# and move the elements that are adjacent

# Recursive functions call on themselves to process data until a goal has been met or it runs out of items to process
# In this example it continues to go over the dataset until it doesn't see any further change in position from sorting

def bubbleSort(arr):
    # Get the length of the array so we know how far to look
    length = len(arr)
    changed = False
    for i in range(length-1):
        # changed will let us keep track of whether anything was changed on the last pass
        if arr[i] > arr[i+1]:
               # Swaps the position of the two elements so the lower value is lower in the order
               arr[i], arr[i+1] = arr[i+1], arr[i]
               changed = True
    # To avoid unneeded processing we break if no changes were made, meaning it is done sorting
    if changed == False:
            return
    else:
        bubbleSort(arr)

# Execute the sort
bubbleSort(data)

# Show sorted array versus original
print("Unsorted array: ")
for i in range(len(dataOrig)):
    print(dataOrig[i])
print("Sorted array: ")
for i in range(len(data)):
    print(data[i])
