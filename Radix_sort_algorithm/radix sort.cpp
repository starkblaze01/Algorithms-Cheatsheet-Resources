#include <iostream>
using namespace std;
void counting_sort(int a[],int n,int e){
    int o[n];
    int c[10];
    int i;
    for(i=0;i<10;i++){
        c[i]=0;
    }
    for(i=0;i<n;i++){
        c[(a[i]/e)%10]++;
    }
    for(i=1;i<10;i++){
        c[i]=c[i]+c[i-1];
    }
    for(i=n-1;i>=0;i--){
        o[c[(a[i]/e)%10]-1]=a[i];
        c[(a[i]/e)%10]--;
    }
    for(i=0;i<n;i++){
        a[i]=o[i];
    }
}
void radix_sort(int a[],int n,int k){
    int e;
    for(e=1;k/e>0;e=e*10){
        counting_sort(a,n,e);
    }
}

int main()
{
    int n;
    cin>>n;
    int i,k;
    k=0;
    int a[n];
    for(i=0;i<n;i++){
        cin>>a[i];
        if(k<a[i]){
            k=a[i];
        }
    }
    radix_sort(a,n,k);
    for(i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}