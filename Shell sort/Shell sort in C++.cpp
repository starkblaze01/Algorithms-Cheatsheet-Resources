// C++ implementation of Shell Sort 
#include <iostream> 

/* function to sort arr using shellSort */
void shellSort(int arr[], int n) 
{ 
	// Start with a big gap, then reduce the gap 
	for (int gap = n / 2; gap > 0; gap /= 2) { 
		// Do a gapped insertion sort for this gap size. 
		// The first gap elements arr[0..gap-1] are already in gapped order 
		// keep adding one more element until the entire array is 
		// gap sorted 
		for (int i = gap; i < n; i += 1) { 
			// add arr[i] to the elements that have been gap sorted 
			// save arr[i] in temp and make a hole at position i 
			int temp = arr[i]; 

			// shift earlier gap-sorted elements up until the correct 
			// location for arr[i] is found 
			int j; 
			for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) 
				arr[j] = arr[j - gap]; 

			// put temp (the original arr[i]) in its correct location 
			arr[j] = temp; 
		} 
	} 
} 

void printArray(int arr[], int n) 
{ 
	for (int i = 0; i < n; i++) 
		std::cout << arr[i] << " "; 
	std::cout << "\n"; 
} 

int main() 
{ 
	int arr[] = { 12, 34, 54, 2, 3 }; 
	int n = sizeof(arr) / sizeof(arr[0]); 

	std::cout << "Array before sorting: \n"; 
	printArray(arr, n); 

	shellSort(arr, n); 

	std::cout << "Array after sorting: \n"; 
	printArray(arr, n); 
} 
