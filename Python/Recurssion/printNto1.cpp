#include <bits/stdc++.h>
using namespace std;
void linearNto1(int n){
    if(n==0){
        return;
    }
    cout<<n<<endl;
    linearNto1(n-1);
}
int main(){
    int n;
    cout<<"Enter the number till which you want to print: ";
    cin>>n;
    linearNto1(n);
    return 0;
}
