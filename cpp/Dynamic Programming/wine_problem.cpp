/*
Problem statement:

Given n wines in a row, with integers denoting the cost of each wine respectively. Each year you can sale the first or the last wine in the row. 
Let the initial profits from the wines be P1, P2, P3…Pn. On the Yth year, the profit from the ith wine will be Y*P[i], calculate the maximum profit from all the wines.
*/

#include<iostream>
using namespace std;

int Max_pro(int a[],int s, int e, int day){

	if(s>e){ // no bottle
		return 0;
	}

	int startpick = day*a[s] + Max_pro(a,s+1,e,day+1);
	int endpick = day*a[e] + Max_pro(a,s,e-1,day+1);

	return max(startpick,endpick);
}

int topdown(int a[], int i, int j,int day, int dp[][100]){
    if(i>j){
    	dp[i][j] = 0;
    	return dp[i][j];
    }
     
     if(dp[i][j]!=0){ //check
     	return dp[i][j];
     }
    int startpick = day*a[i] + topdown(a,i+1,j,day+1,dp);

    int endpick = day*a[j] + topdown(a,i,j-1,day+1,dp);

    dp[i][j] = 	max(startpick,endpick);

    return dp[i][j];

}

int bottom_up(int a[], int n){

	int dp[100][100] = {0};
	int day = n;

	for(int i=0;i<n;i++){
		dp[i][i] = a[i]*day; // 1 bottle (5th day) - diagonal
	}

	day--;

	for(int len = 2;len<=n;len++){// len = no. of bottles
		int i = 0; // start of range
		int maxi = n-len; //end of range

		while(i<=maxi){

			int j = i+len-1; //endpick index

			int op1 = a[i]*day + dp[i+1][j]; //start pick

			int op2 = a[j]*day + dp[i][j-1]; //end pick

			dp[i][j] = max(op1,op2);

			i++;
		} 
		day--;

	}

 return dp[0][n-1];
}

int main() {

    int dp[100][100] = {0};
    int a[]={2,3,5,1,4};
    int n = sizeof(a)/sizeof(int);
    cout << Max_pro(a,0,n-1,1)<<"\n";
    cout<< topdown(a,0,n-1,1,dp)<<"\n";
    cout<<bottom_up(a,n);
  return 0;
}
