#include<stdio.h>

int lsearch(int ar[],int size,int item);

void main()
{
	int a[20],n,i,index,k;
	printf("Enter size:");
	scanf("%d",&n);
	printf("\nEnter elements:");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	printf("\nEnter search key:");
	scanf("%d",&k);
	index=lsearch(a,n,k);
	if(index==-1)
		printf("\nElement not found!");
	else
		printf("\nElement found at index %d and position %d",index,index+1);
}

int lsearch(int ar[],int size,int item)
{
	int j;
	for(j=0;j<size;j++)
		if(item==ar[j])
			 return j;
	return(-1);
}
