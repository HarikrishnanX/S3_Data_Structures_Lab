#include<stdio.h>
void bsearchrec(int ar[],int item,int beg,int last);
void main()
{int a[20],n,k,b,l,i;
printf("Enter size:");
scanf("%d",&n);
b=0;
l=n-1;
printf("\nEnter elements:");
for(i=0;i<n;i++)
scanf("%d",&a[i]);
printf("\nEnter search key:");
scanf("%d",&k);
bsearchrec(a,k,b,l);
}
void bsearchrec(int ar[],int item,int beg,int last)
{int mid;
if(beg<=last)
{mid=(beg+last)/2;
if(item==ar[mid])
printf("\nElement found at index %d,position %d",mid,mid+1);
else if(item>ar[mid])
{beg=mid+1;
bsearchrec(ar,item,beg,last);
}
else
{last=mid-1;
bsearchrec(ar,item,beg,last);
}
}
else
printf("\nElement not found!");
}
