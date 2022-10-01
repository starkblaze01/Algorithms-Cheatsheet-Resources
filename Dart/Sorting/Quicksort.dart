// program to perform quick sort
import 'dart:io';
import 'dart:core';

// function to swap two elements
void swap(List array_1, int a, int b) {
  int temp = array_1[a];
  array_1[a] = array_1[b];
  array_1[b] = temp;
}

// function to perform partition
int partition(List array_1, int p, int r) {
  int i = p - 1;
  int pivot = array_1[r];
  for (int j = p; j < r; j++) {
    if (array_1[j] <= pivot) {
      i++;
      swap(array_1, i, j);
    }
  }
  swap(array_1, i + 1, r);
  return i + 1;
}

// function to perform the quicksort
void quicksort(List array_1, int p, int r) {
  if (p < r) {
    int q = partition(array_1, p, r);
    quicksort(array_1, p, q - 1);
    quicksort(array_1, q + 1, r);
  }
}

// Driver of Program
void main() {
  // scanning the size of the array
  stdout.write("Enter the size of the array: ");
  int size = int.parse(stdin.readLineSync()!);

  // var array_1 = <int>[];
  List<int> array_1 = [];
  // scanning the elements of the array
  for (var i = 0; i < size; i++) {
    int element = int.parse(stdin.readLineSync()!);
    array_1.add(element);
  }

  // printing the array
  print("Array:");
  print(array_1);

  // assigning the zeroth index of array to p
  int p = 0;

  // assigning the last index of array to r
  int r = array_1.length - 1;

  // calling the quicksort function
  quicksort(array_1, p, r);

  // printing the sorted array
  print("Sorted Array:");
  print(array_1);
}
