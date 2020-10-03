// Hi everyone this is my quick sort implementation in go

package main

import (
	"fmt"
	"math/rand"
)

func main() {
	// This is the input array to be sorted
	testData := []int{846, 502, 4, 9, 38, 67, 109, 438, 650, 17, 4, 4, 4650, 1, 73, 45, 29, 0, 84, 54, 5}

	fmt.Println("Sorted data:", quicksort(testData))
}

func quicksort(arr []int) []int {
	if len(arr) < 2 {
		return arr
	}

	left := 0
	right := len(arr) - 1
	pivot := rand.Int() % len(arr)

	arr[pivot], arr[right] = arr[right], arr[pivot]

	for i, _ := range arr {
		if arr[i] < arr[right] {
			arr[left], arr[i] = arr[i], arr[left]
			left++
		}
	}

	arr[left], arr[right] = arr[right], arr[left]

	quicksort(arr[:left])
	quicksort(arr[left+1:])

	return arr
}
