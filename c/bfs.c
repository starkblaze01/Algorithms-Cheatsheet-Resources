//Code for Breadth first search in C for both directed and undirected graphs
#include<stdio.h>
#include<stdbool.h>
int n;
int front=-1;
int rear=-1;
int queue[100];	//fixing the size of the queue to be 100
bool isEmpty()
{
	if(rear==-1 && front==-1)
		return true;
	else return false;
}
void push(int value)
{
	if(isEmpty()==true)
	{
		front++;
	}
	if(rear>99)
	{
		printf("Queue full, cannot push\n");
	}
	else
	{
		queue[++rear]=value;
	}
}
void pop()
{
	if(isEmpty()==true)
	{
		printf("Nothing to pop\n");
	}
	else if(front!=rear)
	{
		++front;
	}
	else
		front=rear=-1;	//resetting the queue
}

void bfs(int arr[][n], int s)
{
	int i,u;
	int visited[n];
	for ( i = 0; i < n; ++i)
	{
		visited[i]=0;
	}
	visited[s]=1;
	push(s);
	while(isEmpty()==false)
	{
		u=queue[front];
		pop();
		for(i=0;i<n;i++)
		{
			if(arr[u][i]==1 && visited[i]==0)
			{
				push(i);
				visited[i]=1;
			}
		}
		printf("%d ", u);	//Printing the vertex
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
	printf("The bfs output is\n");
	bfs(arr, s);	//Performing the bfs
	}
	else
		printf("Please enter either 1 or 2\n");

}
