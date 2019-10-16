#include <bits/stdc++.h>

//https://www.techiedelight.com/find-number-rotations-circularly-sorted-array/

using namespace std;

//Here the assumption is that the array contains all distinct elements rotated anti-clockwise.

int rotationNum(int arr[], int l, int r, int n)
{
    if(l <= r) //Continuing until atleast one element is present.
    {
        if(arr[l] <= arr[r]) //Condition of array being already sorted
            return l;
        int mid = (l+r)/2;
        int next = (mid + 1) % n;
        int previous = (mid - 1 + n) % n;
        if(arr[mid] <= arr[next] and arr[mid] <= arr[previous])
            return mid;
        else if(arr[mid] <= arr[r]) // If the right array is fully sorted, then just discard it.
            return rotationNum(arr, l, mid - 1, n);
        else if(arr[mid] >= arr[l]) //If the left array is fully sorted, then just discard it.
            return rotationNum(arr, mid + 1, r, n);
    }
    return -1; //Invalid input
}

int main()
{
    int test;
    cin >> test;
    while(test--)
    {
        cout << "Enter number of elements of array" << endl;
        int n;
        cin >> n;
        cout << "Enter the elements: " << endl;
        int arr[n];
        for(int i = 0; i < n; i++)
            cin >> arr[i];
        cout << rotationNum(arr, 0, n-1, n) << endl;
    }
    return 0;
}
