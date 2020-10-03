#include<iostream>
using namespace std;


int top_down(int n, int dp[]){
	if(n==0 || n==1){
		dp[n] = n; // save
		return dp[n];
	}

	if(dp[n]!=-1){ // check
       return dp[n];
	}
   int ans = top_down(n-1, dp)+top_down(n-2,dp);
   dp[n] = ans; // save
	
 return dp[n];

}

int bottom_up(int n){
	int dp[100];

	// initialization with base case

	dp[0] = 0;
	dp[1] = 1;

	for(int i=2;i<=n;i++){
		dp[i] = dp[i-1] + dp[i-2]; // recursive relation
	}

	return dp[n];
}
int main() {

    int n;
    int dp[100];
    cout << "Index of fibonacci number: " << endl;
    cin >> n;
    for(int i=0;i<100;i++){ //initilize with -1 
    	dp[i] = -1;
    }
    cout<<top_down(n, dp)<<"\n";
    cout<<bottom_up(n);
return 0;
}
