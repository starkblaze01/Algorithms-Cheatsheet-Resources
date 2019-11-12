
#include <stdio.h>
#include<stdlib.h>
int swap(int* a,int* b){
   int t=*a;
    *a=*b;
    *b=t;
}
int partition(int A[],int p,int r){
    int x;
    x=A[r];
    int i=p-1;
    for(int j=p;j<r;j++){
        if(A[j]<=x){
            i=i+1;
            swap(&A[i],&A[j]);
        }
    }
     swap(&A[i+1],&A[r]);
     return i+1;
}
int Random_partition(int A[],int p,int r){
    int j=rand() % (r-p+1) + p;
    swap(&A[r],&A[j]);
    return partition(A,p,r);
}
int Randomized_selection(int A[],int p,int r,int i){
    if(p==r){
        return A[p];
    }
    else{
      int  q=Random_partition(A,p,r);
      int   k=q-p+1;
        if(i<=k){
            return Randomized_selection(A,p,q,i);
        }
        else{
            return Randomized_selection(A,q+1,r,i-k);
        }
    }
}

int main()
{
    int n;
    printf("Enter the number of elements : ");
    scanf("%d",&n);
    int i;
    int A[n+1];
    printf("Enter the elements : ");
    for(i=1;i<=n;i++){
        scanf("%d",&A[i]);
    }
    int ith;
    printf("Enter the value of i\n");
    scanf("%d",&ith);
    printf("The ith smallest element is %d",Randomized_selection(A,1,n,ith));

    return 0;
}
