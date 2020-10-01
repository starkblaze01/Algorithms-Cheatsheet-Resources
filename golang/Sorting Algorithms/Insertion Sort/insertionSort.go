package main

import "fmt"

func main() {
	arr := []int{0, 5, 3, 51, 27, 4, 16, 19, 4, 4, 7}
	fmt.Printf("Array before Insertion Sort\t->\t %v\n", arr)

	insertionSort(arr)

	fmt.Printf("Array after Insertion Sort\t->\t %v\n", arr)
}

func insertionSort(arr []int) []int {
	var j, temp int
	for i := 1; i < len(arr); i++ {
		j = i
		temp = arr[i]
		for j > 0 && temp < arr[j-1] {
			arr[j] = arr[j-1]
			j = j - 1
		}
		arr[j] = temp
	}
	return arr
}
