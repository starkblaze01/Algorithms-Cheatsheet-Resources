#include <iostream>
using namespace std;

void swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

void bubbleSort(int *arr, int n)
{
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			if (arr[i] > arr[j])
				swap(arr[i], arr[j]);
}

int main()
{
	int n;
	cout << "Enter the number of Elements: ";
	cin >> n;
	int arr[n];
	cout << "\nEnter the Array: ";
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	bubbleSort(arr, n);

	cout << "\nThe Array after sorting is: ";
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
}