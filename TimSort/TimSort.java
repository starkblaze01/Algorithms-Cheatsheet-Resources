import java.util.Arrays;

/**
 * This class holds an example for a Tim-Sort implementation with a main as an
 * example.
 *
 *
 * Timsort is a hybrid stable sorting algorithm, derived from merge sort and
 * insertion sort, designed to perform well on many kinds of real-world data.
 * Timsort was designed to take advantage of runs of consecutive ordered
 * elements that already exist in most real-world data, natural runs. It
 * iterates over the data collecting elements into runs, and simultaneously
 * merging those runs together. When there are runs, doing this decreases the
 * total number of comparisons needed to fully sort the list.
 *
 *
 * We divide the Array into blocks known as Run. We sort those runs using insertion sort 
 * one by one and then merge those runs using combine function used in merge sort. 
 * If the size of Array is less than run, then Array get sorted just by using Insertion Sort. 
 * The size of run may vary from 32 to 64 depending upon the size of the array. 
 * Note that merge function performs well when sizes subarrays are powers of 2. 
 * The idea is based on the fact that insertion sort performs well for small arrays.
 */

public final class TimSort {

	static int RUN = 32;

	// this function sorts array from left index to
	// to right index which is of size atmost THREASHOLD
	public static void insertionSort(int[] arr, int left, int right) {
		for (int i = left + 1; i <= right; i++) {
			int temp = arr[i];
			int j = i - 1;
			while (j >= 0 && arr[j] > temp && j >= left) {
				arr[j + 1] = arr[j];
				j--;
			}
			arr[j + 1] = temp;
		}
	}

	// merge function merges the sorted runs
	public static void merge(int[] arr, int left, int mid, int right) {

		int leftArryLen = mid - left + 1, rightArrLen = right - mid;
		int[] leftArr = new int[leftArryLen];
		int[] rightArr = new int[rightArrLen];

		for (int x = 0; x < leftArryLen; x++) {
			leftArr[x] = arr[left + x];
		}

		for (int x = 0; x < rightArrLen; x++) {
			rightArr[x] = arr[mid + 1 + x];
		}

		int i = 0;
		int j = 0;
		int k = left;

		while (i < leftArryLen && j < rightArrLen) {
			if (leftArr[i] <= rightArr[j]) {
				arr[k] = leftArr[i];
				i++;
			} else {
				arr[k] = rightArr[j];
				j++;
			}
			k++;
		}

		// copy remaining elements of left, if any
		while (i < leftArryLen) {
			arr[k] = leftArr[i];
			k++;
			i++;
		}

		// copy remaining element of right, if any
		while (j < rightArrLen) {
			arr[k] = rightArr[j];
			k++;
			j++;
		}
	}

	public static void timSort(int[] arr) {
		int length = arr.length;

		// Sort individual subarrays of size THRESHOLD
		for (int i = 0; i < length; i += RUN) {
			// perform insertion sort
			insertionSort(arr, i, Math.min((i + 31), (length - 1)));
		}

		for (int size = RUN; size < length; size = 2 * size) {
			for (int left = 0; left < length; left += 2 * size) {
				int mid = left + size - 1;
				int right = Math.min((left + 2 * size - 1), (length - 1));
				// perform merge sort
				merge(arr, left, mid, right);
			}
		}
	}

	public static void main(String[] args) {
		int[] arr = { 10, 3, 2, 19, 7, 15, 23, 13, 1 };
		System.out.println(Arrays.toString(arr));
		timSort(arr);
		System.out.println(Arrays.toString(arr));
	}
}
