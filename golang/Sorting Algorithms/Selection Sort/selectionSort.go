package main

import "fmt"

func main() {
	arr := []int{3, 8, 11, 12, 5, 4, 5, 2, 1, 10}

	fmt.Println("Array before Selection Sort")
	fmt.Println(arr)
	
	selectionSort(arr)
	
	fmt.Println("Array after Selection Sort")
	fmt.Println(arr)
}

func selectionSort(arr []int) {
	for i := 0; i < len(arr) - 1; i++ {
		for j := i + 1; j < len(arr); j++ {
			if arr[j] < arr[i] {
				arr[j], arr[i] = arr[i], arr[j] //Swap elements
			}
		}
	}
}
