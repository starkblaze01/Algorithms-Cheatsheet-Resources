package main

import "fmt"

func main() {
	arr := []int{0, 5, 3, 2, 8, 4, 16, 29,1 4, 4, 7}
	fmt.Printf("Array before Bubble Sort\t->\t %v\n", arr)

	bubbleSort(arr)

	fmt.Printf("Array after Bubble Sort\t->\t %v\n", arr)
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
