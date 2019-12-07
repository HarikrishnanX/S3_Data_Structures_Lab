#include<stdio.h>
int n,k=1;
void quicksort(int A[],int lb,int ub,int n);
int partition(int X[],int lwb,int upb,int n);
void main()
{int ar[10],i,l,u;
printf("Enter size:");
scanf("%d",&n);
l=0;
u=n-1;
printf("\nEnter elements:");
for(i=0;i<n;i++)
scanf("%d",&ar[i]);
quicksort(ar,l,u,n);
printf("\nArray after quicksort:");
for(i=0;i<n;i++)
printf("%d ",ar[i]);
}
void quicksort(int A[],int lb,int ub,int n)
{if(lb>=ub)
return;
int j;
j=partition(A,lb,ub,n);
quicksort(A,lb,j-1,n);
quicksort(A,j+1,ub,n);
}
int partition(int X[],int lwb,int upb,int n)
{int temp,up,down,j,pivot;
pivot=X[lwb];
up=upb;
down=lwb;
while(down<up)
{while(X[down]<=pivot&&down<up)
down++;
while(X[up]>pivot)
up--;
if(down<up)
{temp=X[down];
X[down]=X[up];
X[up]=temp;
}
}
X[lwb]=X[up];
X[up]=pivot;
printf("\nArray after Partition %d:",k);
for(j=0;j<n;j++)
{printf("%d ",X[j]);
}
printf("\n");
k=k+1;
return up;
}
