main() {
  List<int> arr = [10, 2, 3, 21, 12, 8, 32, 22, 13, 6];
  print("Array before bubble sort \t->\t$arr");
  print("Array after bubble sort \t->\t${bubbleSort(arr)}");
}

List<int> bubbleSort(List<int> arr) {
  for (var i = 0; i < arr.length - 1; i++) {
    for (var j = 0; j < arr.length - 1 - i; j++) {
      if (arr[j] > arr[j + 1]) {
        var temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
  return arr;
}
