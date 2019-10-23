/*Question: Given a
sorted array that has been rotated, find the index upto which array is sorted*/

#include <bits/stdc++.h>

using namespace std;

//We have to find such a number jiske right side k saare number last se chhote aur left side k number last se bade ho

int solve(int arr[], int l, int r)
{
    int last = arr[r];
    if(r >= l)
    {
        int mid = l + (r-l)/2;
        if(arr[mid] > last)
            return solve(arr, mid + 1, r);
        else if(arr[mid] < last)
            return solve(arr, l, mid - 1);
        else
            return mid;
    }
}

int main()
{
    int arr[7] = {3,4,5,6, 7, 1,2};
    cout << solve(arr, 0, 6) << endl;
    return 0;
}
