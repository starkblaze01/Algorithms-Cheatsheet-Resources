#include <bits/stdc++.h>

using namespace std;

int res = -1;
int result = -1;

int ceil(int arr[], int l, int r, int key)
{
    if(l <= r)
    {
        int mid = (l+r)/2;
        if(arr[mid] == key)
            return arr[mid];
        else if(arr[mid] > key)
        {
            res = arr[mid];
            return ceil(arr, l, mid - 1, key);
        }
        else
        {
            return ceil(arr, mid + 1, r, key);
        }
    }
    return res;
}

int floor(int arr[], int l, int r, int key)
{
    int mid = (l+r)/2;
    if(l <= r)
    {
        if(arr[mid] == key)
            return arr[mid];
        else if(arr[mid] > key)
            return floor(arr, l, mid - 1, key);
        else if(arr[mid] < key)
        {
            result = arr[mid];
            return floor(arr, mid + 1, r, key);
        }
    }
    return result;
}


int main()
{
    int test;
    cin >> test;
    while(test--)
    {
        int n;
        cin >> n;
        int arr[n];
        for(int i = 0; i < n; i++)
            cin >> arr[i];
        for(int i = 0; i < 11; i++)
        {
            cout << "Ceiling and Floor for " << i << " is " << ceil (arr, 0, n-1, i)<< " and " <<floor(arr, 0, n-1, i) << endl;
            result = -1;
            res = -1;
        }

    }
    return 0;
}
