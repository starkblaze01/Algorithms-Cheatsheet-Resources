#include<bits/stdc++.h>
using namespace std;
void linear1toN(int n){
    if(n==0){
        return;
    }
    linear1toN(n-1);
    cout<<n<<endl;
}
int main(){
    int n;
    cout<<"Enter the number till which you want to print: ";
    cin>>n;
    linear1toN(n);
    return 0;
}