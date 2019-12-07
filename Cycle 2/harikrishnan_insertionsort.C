#include<stdio.h>
void insort(int ar[],int size);
void main()
{int a[20],n,i;
printf("Enter size:");
scanf("%d",&n);
printf("\nEnter elements:");
for(i=0;i<n;i++)
scanf("%d",&a[i]);
insort(a,n);
printf("\nArray after insertion sort:");
for(i=0;i<n;i++)
printf("%d ",a[i]);
}
void insort(int ar[],int size)
{int i,j,k,t;
for(i=0;i<size;i++)
{t=ar[i];
j=i-1;
while((t<ar[j])&&(j>=0))
{ar[j+1]=ar[j];
j=j-1;
}
ar[j+1]=t;
printf("\nArray after pass %d:");
for(k=0;k<size;k++)
printf("%d ",ar[k]);
}
}
