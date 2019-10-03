range_arr = int(input("Enter range of array : "))

arr = []

for i in range(range_arr):
    arr.append(int(input("Enter value at position {} : ".format(i + 1))))

print("You have enter : ", arr)

# test-case
# range_arr = 5
# arr = [50, 20, 10, 30, 40]

target_index = 0
min_value = arr[0]

for i in range(0, range_arr):
    min_value = arr[i]

    for j in range(i, range_arr):
        if min_value > arr[j]:
            min_value = arr[j]

    temp = arr[i]

    var1 = arr.index(min_value)

    arr[i] = min_value

    arr[var1] = temp

    print("Iteration {} : ".format(i + 1), arr)


print("After Selection Sort : ", arr)
