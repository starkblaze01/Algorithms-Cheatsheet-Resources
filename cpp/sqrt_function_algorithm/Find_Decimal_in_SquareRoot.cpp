#include<bits/stdc++.h>
using namespace std;

int sqaureRootInt(long long int N)
{
  long long int s=0,ans=-1;
  long long int e=N;
  unsigned long long int mid=s+(e-s)/2;
   
   while(s<=e){
       if(mid*mid == N){
           return mid;
       }
       else if(mid*mid<N){
           ans= mid;
           s=mid+1;
       }
       else{
           e=mid-1;
       }
       mid=s+(e-s)/2;
   }
   return ans;
   
}

double morePrecision(int n, int precision, int tempSol){
    double factor = 1;
    double ans = tempSol;
    for(int i = 0;i<precision;i++){
        factor = factor/10;
        //factor: 0.1 -> 0.01 -> 0.001 and so on
        for(double j = ans;j*j<n;j+=factor){
            ans = j;
        }
    }
    return ans;
}


int main(){
    int n;
    cout <<" Enter the number " << endl;
    cin >> n;

    //tempSol will store integer part of the square root
    int tempSol = sqaureRootInt(n);
    cout <<" Answer is " << morePrecision(n, 3, tempSol) << endl;
    
    return 0;
}



