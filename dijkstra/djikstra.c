/*
  Files 	:	 djikstra.c,input.txt

  Author 	:	 Yash Agrawal (B16120)
  
  Created 	: 	 4th May 2018


 **	This file includes program to find shortest path using djikstra's algorithm  **

 **	Input is taken from file "input.txt"  **


Input file format :
-----------------

Number_of_vertices  source	
v1 v2 weight(v1,v2)				where v1,v2 can be any two vertices with corresponding weight
.  .  .
.  .  .
.  .  .
.  .  .
.  .  .
*/

//	========================================  Program  ==========================================================



#include <stdio.h>									// Header Files included
#include <string.h>
#include <stdlib.h>							
#include <math.h>
#define inf 999999999								// Infinfite is defined as inf


//=======================================================================================================

int visited[200],arr[200][200];
int weight[200][200];
int vertex1,vertex2,weigh,distance[200];
int src,len,edges,sum=0;
		
//========================================================================================================

void Read_file()								// Read file function is used to get input from txt file
{

	FILE*p=fopen("input.txt","r");
	printf("axD\n");
	fscanf(p,"%d %d %d",&len,&edges,&src);
    printf("%d %d %d\n",len,src,edges);
	//while(!feof(p))
	for(int i=0;i<edges;i++)
	{
		fscanf(p,"%d %d %d",&vertex1,&vertex2,&weigh);
		arr[vertex1][vertex2] = 1;							// Adjacency Matrix for given input
		arr[vertex2][vertex1] = 1;
		weight[vertex1][vertex2] = weigh;					// Weight of each pair of vertices
		weight[vertex2][vertex1] = weigh;
	}
}

//=========================================================================================================

void Make_infinite()
{
	for(int i=1;i<=len;i++){
		visited[i]=0;						// Initially distance of each vertex from source is infinite
		distance[i]=inf;
	}
}

//==========================================================================================================

void Find_path(int source)					// Finding Path from source using djikstra's algorithm
{
	distance[source] = 0;					// distance from source to source will be zero
    int l,k,m,MIN;
	for(int i=1;i<=len;i++)
	{
		int min = inf;
		int index;

		for(int j=1;j<=len;j++)
		{
			if(visited[j]==0 && distance[j]<min)
			{
				min = distance[j];			// find minimum distance vertex which is not visited yet
				index = j;
			}
		}

		visited[index]=1;					// After processing mark the vertex as visited
        printf("%d\n",index);
		for(int j=1;j<=len;j++)
		{     

			 for(k=1;k<=len;k++)
             {   if(weight[index][k]!=0)
             	 MIN=weight[index][k];
    		    
     		 	 for(l=k+1;l<=len;l++)
       				{
       	 
    	 			if(weight[index][l]<MIN && weight[index][l]!=0)
    	 			{
    	 				MIN=weight[index][l];
    	 			     m=l;
    	 			}
       				}
       			}
       		printf("index of min%d\n",l);

			if(visited[j]==0 && arr[index][j]==1 && distance[j] > (distance[index] + weight[index][j]))
			{   printf("index%d i%d\n",index,i );
				distance[j] = distance[index] + weight[index][j];
				sum=sum+weight[index][j];
				printf("s%d\n",sum);
				j=len+1;
			}
		}
	}
}

//===========================================================================================================

void Output()
{
	for(int i=1;i<=len;i++)
{   
	if(i!=src)
	{ if(distance[i]==inf)
	printf("INF\n"); 
	else
	printf("Shortest distance  from  %d  to  %d  is  %d \n",src,i,distance[i]); 
	}
}
}
//=============================================================================================================

int main()
{  // printf("axaD\n");
	//Read_file();			// Read_file function used to take input from txt file
 	scanf("%d %d %d",&len,&edges,&src);
    //printf("%d %d %d\n",len,src,edges);
	for(int i=0;i<edges;i++)
	{
		scanf("%d %d %d",&vertex1,&vertex2,&weigh);
		arr[vertex1][vertex2] = 1;							// Adjacency Matrix for given input
		arr[vertex2][vertex1] = 1;
		weight[vertex1][vertex2] = weigh;					// Weight of each pair of vertices
		weight[vertex2][vertex1] = weigh;
	}
	Make_infinite();		// Make_infinite function is used to assign infinite value to distance of each vertex
	
	Find_path(src);			// Find_Path function is used to find shortest path of each vertex from source	

	//Output();				// Output fuction is used to Output distance of each vertex from given source
	printf("sum=%d\n",sum);
	return 0;
}
