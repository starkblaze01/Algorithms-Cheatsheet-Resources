/*package whatever //do not write package name here */

import java.util.*;
import java.lang.*;
import java.io.*;

class cylicallyrotate {
    static void rotate(int arr[]) 
    { 
       int x = arr[arr.length-1], i; 
       for (i = arr.length-1; i > 0; i--) 
          arr[i] = arr[i-1]; 
       arr[0] = x; 
       for(i=0;i<arr.length;i++)
		  System.out.println(arr[i]);
    } 
	public static void main (String[] args) throws java.lang.Exception
	{
		try {
		    Scanner sc = new Scanner(System.in);
		    int t = sc.nextInt();
		    while(t-->0)
		    {
		        int n = sc.nextInt();
		        int a[] = new int[n];
		        for(int i=0;i<n;i++)
		            a[i] = sc.nextInt();
		        rotate(a);
		    }
		}
		catch(Exception e)
		{
		    return;
		}
	}
}