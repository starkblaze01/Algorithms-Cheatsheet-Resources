#include <bits/stdc++.h>
using namespace std;
void summation(int n, int sum){
    if(n==0){
        cout<<sum<<endl;
        return;
    }
    summation(n-1,sum+n);
}
int main(){
    int n;
    cout<<"Enter the number till which you want to print: ";
    cin>>n;
    summation(n,0);
    return 0;
}