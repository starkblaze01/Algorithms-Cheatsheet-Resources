// Java code for kth largest element in an array
// using heap/priority queue
import java.util.*;

class kLargestElement 
{
	public static int kthLargest(int[] arr, int k)
	{
    	PriorityQueue<Integer> pq = new PriorityQueue<>();
    	for(int i = 0; i < k; i++)
    		pq.add(arr[i]);
    	for(int i = k;i < arr.length; i++)
    	{
     		if(pq.peek()<arr[i])
      		{
        		pq.poll();
        		pq.add(arr[i]);
      		}
    	}
    	return pq.peek();
  	}

	// driver program
	public static void main(String[] args)
	{
		int arr[] = { 12, 3, 5, 7, 19 };
		int k = 5;
		System.out.print("K'th largest element is " + kthLargest(arr, k));
	}
}

