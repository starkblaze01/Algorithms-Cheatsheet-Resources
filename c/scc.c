#include <stdio.h>
#include <stdbool.h>
int n;
int stack[20];	//setting max vertices to be 20
int rear=0;
void dfs2(int arr[][n], int src, int visited[])	//performs normal dfs
{
	if(visited[src]==1)
		return;
	int i;
	printf("%d ", src);
	visited[src]=1;
	for(i=0;i<n;i++)
	{
		if(arr[src][i]==1 && visited[i]==0)
		{
			dfs2(arr, i, visited);
		}
	}
}
void dfs(int arr[][n], int src, int visited[])	//performs topological sorting
{
	int i;
	//printf("%d ", src);
	if(visited[src]==1)
		return;
	visited[src]=1;
	for(i=0;i<n;i++)
	{
		if(arr[src][i]==1 && visited[i]==0)
		{
			dfs(arr, i, visited);
		}
	}
	stack[rear++]=src;
}
int main()
{
	int x,y,i,j,e,flag;
	printf("Enter the number of vertices in the graph\n");
	scanf("%d",&n);
	int arr[n][n];
	int arrrev[n][n];
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			arr[i][j]=0;
	}	
	printf("Enter the number of edges\n");
	scanf("%d",&e);

	printf("Enter the source and destination vertex\n");
	for(i=0;i<e;i++)
	{
		scanf("%d%d",&x,&y);
		arr[x][y]=1;
		arrrev[y][x]=1;
	}
	printf("Printing the adjacency matrix\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			printf("%d ",arr[i][j]);
		printf("\n");
	}

	int visited[n];
	for (i = 0; i < n; ++i)
	{
		visited[i]=0;
	}
	//printf("The dfs output is\n");
	for (int i = 0; i < n; ++i)
	{
		dfs(arr, i, visited);	//Performing the dfs
	}

	printf("Topologically sorted vertices are\n");
	for (int i = n-1; i >=0; --i)
	{
		printf("%d ", stack[i]);
	}
	printf("\n");
	for (i = 0; i < n; ++i)
	{
		visited[i]=0;
	}
	printf("Strongly connected componenets are\n");
	for (int i = n-1; i >= 0; --i)
	{
		dfs2(arrrev, stack[i], visited);	//using the reversed graph
		printf("\n");
	}
}
