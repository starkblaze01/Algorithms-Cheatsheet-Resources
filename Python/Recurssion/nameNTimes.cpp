#include <bits/stdc++.h>
using namespace std;
void name(int n,string s){
    if(n==0){
        return;
    }
    cout<<s<<endl;
    name(n-1,s);
}
int main(){
    int n;
    cout<<"Enter the number of times you want to print your name: ";
    cin>>n;
    string s;
    cout<<"Enter your name: ";
    cin>>s;
    name(n,s);
    return 0;
}