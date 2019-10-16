import java.util.Scanner;

public class InsertionSort {
	int A[];
	
	InsertionSort(int length, Scanner conin) {
		A = new int[length];
		for(int i = 0; i < length; i++) {
			A[i] = conin.nextInt();
		}
	}

	void InsertionSort() {
		for(int j = 1; j < A.length; j++) {
			int key = A[j];
			int i = j-1;
			while(i >= 0 && A[i] > key) {
				A[i+1] = A[i];
				i--;
			}
			A[i+1] = key;
		}
	}

	void display() {
		for(int i = 0; i < A.length; i++) {
			System.out.print(A[i]);
			if(i != A.length - 1) System.out.print(", ");
			else System.out.println();
		}
	}

	public static void main(String args[]) {
		Scanner conin = new Scanner(System.in);
		int length = conin.nextInt();
		InsertionSort obj = new InsertionSort(length,conin);
		obj.display();
		obj.InsertionSort();
		obj.display();
	}
}