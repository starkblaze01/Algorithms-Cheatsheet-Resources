// Kadane's algorithm consists of a scan through the array values, computing at each position the maximum (positive sum) subarray ending at that position
// Further reading - https://en.wikipedia.org/wiki/Maximum_subarray_problem#Kadane's_algorithm

package main

import "fmt"

func main() {
	a := []int{-2, -3, 4, -1, -2, 1, 5, -3}
	res := lscs(a)
	fmt.Println("Sum : ", res[0], ", i : ", res[1], ", j : ", res[2])
	res = lscsKadane(a)
	fmt.Println("Sum : ", res[0], ", i : ", res[1], ", j : ", res[2])

	a = []int{-2, -3, -4, -1, -2, -1, -5, -3}
	res = lscs(a)
	fmt.Println("Sum : ", res[0], ", i : ", res[1], ", j : ", res[2])
	res = lscsKadane(a)
	fmt.Println("Sum : ", res[0], ", i : ", res[1], ", j : ", res[2])
}

func lscs(a []int) (res [3]int) {
	res = [3]int{}
	var pre int
	for i := range a {
		pre = a[i]
		for j := i + 1; j < len(a); j++ {
			pre = pre + a[j]
			if res[0] < pre {
				res[0] = pre
				res[1] = i
				res[2] = j
			}
		}
	}
	return
}

func lscsKadane(a []int) (res [3]int) {
	maxEndingHere := a[0]
	maxSoFar := a[0]
	maxStart := 0
	maxEnd := 0
	for i := range a {
		maxEndingHere = max(a[i], maxEndingHere+a[i])
		if maxEndingHere == a[i] {
			maxStart = i
		}
		maxSoFar = max(maxSoFar, maxEndingHere)
		if maxSoFar == maxEndingHere {
			maxEnd = i
		}
	}
	return [3]int{maxSoFar, maxStart, maxEnd}
}

func max(a int, b int) int {
	if a > b {
		return a
	}
	return b
}
