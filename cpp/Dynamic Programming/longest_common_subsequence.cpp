#include <iostream>
#include<cstring>
using namespace std;

int lcs(char s1[], char s2[], int m, int n){

	if(m==0 || n==0){
		return 0;
	}

	if(s1[m-1] == s2[n-1]){ // start from last
		return 1+ lcs(s1,s2,m-1,n-1);
	}
	else{
		int op1 = lcs(s1,s2,m,n-1);
		int op2 = lcs(s1,s2,m-1,n);
		return max(op1,op2); 
	}
}
int top_down(char s1[], char s2[], int m, int n, int dp[][100]){

	if(m==0 || n==0){
		dp[m][n] = 0;
		return 0;
	}

	if(dp[m][n]!=-1){
		return dp[m][n];
	}

	if(s1[m-1] == s2[n-1]){ // start from last
		dp[m][n] = 1+ top_down(s1,s2,m-1,n-1,dp);
		return 1+ top_down(s1,s2,m-1,n-1,dp);
	}
	else{
		int op1 = top_down(s1,s2,m,n-1,dp);
		int op2 = top_down(s1,s2,m-1,n,dp);
		dp[m][n] = max(op1,op2);
		return max(op1,op2); 
	}
}

int bottom_up(char s1[], char s2[], int m,int n){

	int dp[100][100] = {0};

	for(int i=0;i<=m;i++){
		for(int j=0;j<=n;j++){

			if(i==0 || j==0){
				dp[i][j] = 0;
			}
			else if(s1[i-1]==s2[j-1]){
				dp[i][j] = 1 + dp[i-1][j-1];
			}
			else{
				dp[i][j]= max(dp[i-1][j], dp[i][j-1]);
			}
		}
	}

	return dp[m][n];
}

int main()
{
	char s1[] ="AGGTAB";
	char s2[] ="GXTXATB";
	int m = strlen(s1);
  int n = strlen(s2);
         int dp[100][100];
         for(int i=0; i<100;i++){
    	     for(int j=0;j<100;j++){
    		    dp[i][j] = -1;
    	     }
         }
	cout << lcs(s1,s2, m, n)<<"\n";
	cout<<top_down(s1,s2,m,n,dp)<<"\n";
	cout<<bottom_up(s1,s2, m, n);
	return 0;
}
