// Code for DFS in c using adjacency matrix for both directed and undirected graphs
#include <stdio.h>
#include <stdbool.h>
int n;
void dfs(int arr[][n], int src, int visited[])
{
	int i;
	printf("%d ", src);
	visited[src]=1;
	for(i=0;i<n;i++)
	{
		if(arr[src][i]==1 && visited[i]==0)
		{
			dfs(arr, i, visited);
		}
	}
}
int main()
{
	int x,y,i,j,e,flag;
	printf("Enter the number of vertices in the graph\n");
	scanf("%d",&n);
	int arr[n][n];
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			arr[i][j]=0;
	}	
	printf("Enter the number of edges\n");
	scanf("%d",&e);
	printf("enter 1 for directed and 2 for undirected graph\n");
	scanf("%d",&flag);
	if(flag==1 || flag==2)
	{
	printf("Enter the source and destination vertex\n");
	for(i=0;i<e;i++)
	{
		scanf("%d%d",&x,&y);
		arr[x][y]=1;
		if(flag==2)
			arr[y][x]=1;
	}
	printf("Printing the adjacency matrix\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			printf("%d ",arr[i][j]);
		printf("\n");
	}
	int s;
	printf("Enter the source\n");
	scanf("%d",&s);
	int visited[n];
	for (i = 0; i < n; ++i)
	{
		visited[i]=0;
	}
	printf("The dfs output is\n");
	dfs(arr, s, visited);	//Performing the dfs
	}
	else
		printf("Please enter either 1 or 2\n");
}
