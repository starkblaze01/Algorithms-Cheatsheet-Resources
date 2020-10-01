#include<bits/stdc++.h>

  using namespace std;

   int Binary_search(int arr[],int l,int r, int key)
 
  {
       if(l<=r)
     {
         int mid = l+((r-l)/2);
         
         if(arr[mid]==key)
          return 1;
          
          else if(arr[mid]>key)
           return Binary_search(arr,l,mid-1,key);
           
           else
             return Binary_search(arr,mid+1,r,key);
     }
     
     return 0;
 }

   int main()
 {
   int arr[]={3,4,5,6,7,8,4,5,2,8,9,13,14,17,19};
   
   int n=sizeof(arr)/sizeof(arr[0]);
   
    int key=79;
   
   sort(arr,arr+n);
   
    if(Binary_search(arr,0,n-1,key))
     cout<<"key is found in given array"<<endl;
     
     else
      cout<<"key is not found in given array"<<endl;
 }
