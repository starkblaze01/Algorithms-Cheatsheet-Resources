// C++ program for coin change problem. 
#include<bits/stdc++.h> 

using namespace std; 

int count( int S[], int m, int n ) 
{ 
	int i, j, x, y; 

	
	int table[n + 1][m]; 

	for (i = 0; i < m; i++) 
		table[0][i] = 1; 


	for (i = 1; i < n + 1; i++) 
	{ 
		for (j = 0; j < m; j++) 
		{ 
		
			x = (i-S[j] >= 0) ? table[i - S[j]][j] : 0; 

			y = (j >= 1) ? table[i][j - 1] : 0; 

			table[i][j] = x + y; 
		} 
	} 
	return table[n][m - 1]; 
} 

 
int main() 
{   
    int m , n ; 
    cout<<"Enter number of coins\n" ; 
    cin>>m ; 
	int arr[m]  ;
    for(int i  = 0 ; i<m ; i++)
    {
        cin>>arr[i] ; 
    } 
	cout<<"Enter Value\n" ; 
    cin>>n ; 
    cout<<"Answer " ; 
	cout << count(arr, m, n); 
	return 0; 
} 

