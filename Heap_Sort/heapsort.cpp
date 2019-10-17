#include <bits/stdc++.h>

using namespace std;
void heapify(int arr[],int n,int i){
    int L=i;
    int l=2*i+1;
    int r=2*i+2;
    if(l<n && arr[L]<arr[l]){
       L=l;
    }
    if(r<n && arr[L]<arr[r]){
        L=r;
    }
    if(L!=i){
        swap(arr[i],arr[L]);
         heapify(arr,n,L);
    }
   
}
void heap_sort(int arr[],int n){
    int i;
    for(i=n/2-1;i>=0;i--){
        heapify(arr,n,i);
    }
    for(i=n-1;i>=0;i--){
        swap(arr[0],arr[i]);
        heapify(arr,i,0);
    }
}
void printarray(int arr[],int n){
    int i;
    for(i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
}
int main()
{
    int n,i;
    cout<<"Enter the total number of inputs\n";
    cin>>n;
    int arr[n];
    cout<<"Enter the numbers to be sorted\n";
    for(i=0;i<n;i++){
        cin>>arr[i];
    }
    heap_sort(arr,n);
    cout<<"The sorted array is\n";
    printarray(arr,n);
    return 0;
}
