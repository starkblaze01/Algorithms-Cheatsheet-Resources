/*

CODE SUBMITTED BY:- SUBHAM SAHU
GITHUB URL:- https://github.com/subhamx

The following code expects user to input some numbers. The code sorts the given numbers usng radix sort.


*/

#include<bits/stdc++.h>

using namespace std;

void sortByIndex(int* A, int n, int index){
    int count[10]={ 0 };
    for(int i=0; i<n; i++){
        int num;
        if(index==0){
            num = A[i]%10;
        }else{
            num = (A[i]/(int)pow(10, index))%10;
        }
        count[num]++;
    }
    for(int i=1; i<10; i++){
        count[i]+=count[i-1];
    }
    int output[n];
    for(int i=n-1; i>=0; i--){
        int num;
        if(index==0){
            num = A[i]%10;
        }else{
            num = (A[i]/(int)pow(10, index))%10;
        }
        output[count[num]-1] = A[i];
        count[num]--;
    }
    for(int i=0; i<n; i++){
        A[i]=output[i];
    }
}
int main(){

    int n = 8;
    cout<<"Enter the number of Elements:"<<endl;
    cin>>n;
    int A[n];
    cout<<"Enter "<<n<<" Elements:"<<endl;
    for(int i=0; i<n; i++){
        cin>>A[i];
    }
    int maxDigits = 0;
    for(int i=0; i<n; i++){
        int temp=0, num=A[i];
        while(num){
            temp++;
            num/=10;
        }
        if(maxDigits<temp){
            maxDigits=temp;
        }
    }
    cout<<"ORIGINAL ARRAY:\n";
    for(int i=0; i<n; i++){
        cout<<A[i]<<" ";
    }
    cout<<endl;
    for(int i=0; i<maxDigits; i++){
        sortByIndex(A, n, i);
    }
    cout<<"SORTED ARRAY:\n";
    for(int i=0; i<n; i++){
        cout<<A[i]<<" ";
    }
    cout<<endl;
}