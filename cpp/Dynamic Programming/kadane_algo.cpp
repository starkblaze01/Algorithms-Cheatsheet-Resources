#include<bits/stdc++.h> 
using namespace std; 

int maxSubArraySum(int a[], int size) 
{ 
int max_so_far = a[0]; 
int curr_max = a[0]; 

for (int i = 1; i < size; i++) 
{ 
		curr_max = max(a[i], curr_max+a[i]); 
		max_so_far = max(max_so_far, curr_max); 
} 
return max_so_far; 
} 

int main() 
{ 

    int n ; 
    cout<<"Enter size of the Array\n" ; 
    cin>>n ; 
    int a[n] ;
    cout<<"Enter array elements\n" ; 
    for(int i =  0 ;i<n ; i++)
    {
        cin>>a[i] ; 
    }
    int max_sum = maxSubArraySum(a, n); 
    cout << "Maximum contiguous sum is " << max_sum; 
    return 0; 
} 
