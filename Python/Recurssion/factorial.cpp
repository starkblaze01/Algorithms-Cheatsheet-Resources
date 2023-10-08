#include <bits/stdc++.h>
using namespace std;
int factorial(int n){
    //calculate factorial till of n
    if(n==0){
        return 1;
    }
    return n*factorial(n-1);

}
int main(){
    int n;
    cout<<"Enter the number till which you want to print: ";
    cin>>n;
    cout<<factorial(n);
    return 0;
}