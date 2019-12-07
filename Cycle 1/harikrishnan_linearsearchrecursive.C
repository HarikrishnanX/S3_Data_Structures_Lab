#include<stdio.h>
void lsearchrec(int ar[],int size,int item,int j);
void main()
{int a[20],n,k,i,index;
printf("Enter size:");
scanf("%d",&n);
printf("\nEnter elements:");
for(i=0;i<n;i++)
scanf("%d",&a[i]);
printf("\nEnter search key:");
scanf("%d",&k);
i=0;
lsearchrec(a,n,k,i);
}
void lsearchrec(int ar[],int size,int item,int j)
{if(item==ar[j])
printf("\nElement found at index %d,position %d",j,j+1);
else if(j==size)
printf("\nElement not found!");
else
{++j;
lsearchrec(ar,size,item,j);
}
}