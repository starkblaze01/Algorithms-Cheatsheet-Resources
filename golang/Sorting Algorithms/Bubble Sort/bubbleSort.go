package main

import "fmt"

func main() {
	arr := []int{0, 5, 3, 5, 7, 4, 6, 9, 4, 4, 7}
	fmt.Printf("Array before Selection Sort\t->\t %v\n", arr)

	bubbleSort(arr)

	fmt.Printf("Array after Selection Sort\t->\t %v\n", arr)
}

func bubbleSort(arr []int) []int {
	for i := 0; i < len(arr)-1; i++ {
		for j := 0; j < len(arr)-i-1; j++ {
			if arr[j] > arr[j+1] {
				var temp = arr[j]
				arr[j] = arr[j+1]
				arr[j+1] = temp
			}
		}
	}
	return arr
}
