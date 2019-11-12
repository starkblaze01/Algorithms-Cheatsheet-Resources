/*
Problem:
you are given a cost matrix named cost with size RXC where R is no. of rows and 
C is no. of columns and a position (m, n) in cost[][].
You have to find out the min cost path to reach (m, n) from (0, 0).
*/

#include<stdio.h>
#define R 3
#define C 3

int min(int x ,int y,int z)
{	
	if (x<y)
		return (x<z) ? x:z ;
	else
		return (y<z) ? y:z ;
} 


int min_dist(int cost[R][C], int m, int n)
{      
	int t[R][C];
	t[0][0] = cost[0][0];

	// set first column
	for(int i =1;i<m;i++)
		t[i][0] = t[i-1][0] + cost[i][0];
		
	// set first row
	for(int j=1;j<n;j++)
		t[0][j] = t[0][j-1] + cost[0][j];
		
	for(int i=1;i<m;i++)
	{
	    for(int j=1;j<n;j++)
	        {
	            t[i][j] = min(t[i][j-1],t[i-1][j-1],t[i-1][j])+cost[i][j]; 
	        }
	}
	return t[m-1][n-1];
}
	

int main()
{	
    int cost[R][C] = { {1,2,3},{4,8,2},{1,5,3} };

	printf("%d\n",min_dist(cost,R,C));
	return 0;
}