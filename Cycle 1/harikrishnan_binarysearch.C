#include<stdio.h>
int bsearch(int ar[],int size,int item);
void main()
{int a[20],n,k,i,index;
printf("Enter size:");
scanf("%d",&n);
printf("\nEnter elements:");
for(i=0;i<n;i++)
scanf("%d",&a[i]);
printf("\nEnter search key:");
scanf("%d",&k);
index=bsearch(a,n,k);
if(index==-1)
printf("\nElement not found!");
else
printf("\nElement found at index %d,position %d",index,index+1);
}
int bsearch(int ar[],int size,int item)
{int beg,mid,last;
beg=0;
last=size-1;
while(beg<=last)
{mid=(beg+last)/2;
if(item==ar[mid])
return mid;
else if(item>ar[mid])
beg=mid+1;
else
last=mid-1;
}
return(-1);
}