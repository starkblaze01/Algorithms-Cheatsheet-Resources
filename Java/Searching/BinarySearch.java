public class BinarySearch {
    
    public int binarySearchRecursively(int[] sortedArray, int key, int low, int high) {

        int middle = (low + high) / 2;
        if (high < low) {
            return -1;
        }

        if(key == sortedArray[middle]) {
            return middle;
        } else if (key < sortedArray[middle]) {
            return binarySearchRecursively(sortedArray, key, low, middle - 1);
        } else {
            return binarySearchRecursively(sortedArray, key, middle + 1, high);
        }
    }
    public static void main(String[] args) {
        int[] sortedArray = {0, 1, 2, 3, 4, 5, 5, 6, 7, 8, 9, 9};
            int key = 6;
        BinarySearch binSearch = new BinarySearch();

            int index = binSearch.binarySearchRecursively(sortedArray, key, 0, sortedArray.length -1);
            System.out.println("Search element in location index : " + index);
    }
}