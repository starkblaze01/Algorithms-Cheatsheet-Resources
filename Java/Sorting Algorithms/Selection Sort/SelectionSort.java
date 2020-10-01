class SelectionSort {

    public static void selectionSort(int[] arr) {
        for (int i = 0; i < arr.length - 1; i++) {
            for (int j = i + 1; j < arr.length; j++) {
                if (arr[j] < arr[i]) {// find smaller number
                    // swap elements
                    int temp = arr[j];
                    arr[j] = arr[i];
                    arr[i] = temp;
                }
            }
        }
    }

    public static void main(String args[]) {
        int[] arr = { 8, 1, 4, 10, 12, 5, 2, 3, 7 };
        System.out.println("Array before Selection Sort");

        for (int i : arr) {
            System.out.print(i + " ");
        }

        selectionSort(arr);// sorting array elements using selection sort

        System.out.println("\nArray after Selection Sort");
        for (int i : arr) {
            System.out.print(i + " ");
        }
    }
}
