#include <bits/stdc++.h>

#define lli long long int

using namespace std;

lli findRotEle(lli arr[], lli l, lli r, lli key)
{
    if(r >= l)
    {
        lli mid = (l + r)/2;
        if(arr[mid] == key)
            return mid;
        if(arr[mid] <= arr[r])
        {
            if(arr[mid] < key and arr[r] >= key)
                return findRotEle(arr, mid+1, r, key);
            else
                return findRotEle(arr, l, mid-1, key);
        }
        else
        {
            if(key >= arr[l] and arr[mid] > key)
                return findRotEle(arr, l, mid-1, key);
            else
                return findRotEle(arr, mid+1, r, key);
        }
    }
    return -1;
}

int main()
{
    lli test;
    cout << "Enter the no. of test cases: ";
    cin >> test;
    while(test--)
    {
        lli n, key;
        cout << "Enter Length of the array: ";
        cin >> n;
        cout <<  "Enter the value you want to find: ";
        cin >> key;
        lli arr[n];
        cout << "Enter Input Array";
        for(lli i = 0; i < n; i++)
            cin >> arr[i];
        cout << findRotEle(arr, 0, n-1, key) << endl;
    }
    return 0;
}
