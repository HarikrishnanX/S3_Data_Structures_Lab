#include<stdio.h>
void main()
{int a[20],n,i,j,k,t,min;
printf("Enter size:");
scanf("%d",&n);
printf("\nEnter elements:");
for(i=0;i<n;i++)
scanf("%d",&a[i]);
for(i=0;i<n-1;i++)
{min=i;
for(j=i+1;j<n;j++)
if(a[j]<a[min])
min=j;
t=a[i];
a[i]=a[min];
a[min]=t;
printf("\nArray after pass %d:",i+1);
for(k=0;k<n;k++)
printf("%d ",a[k]);
}
printf("\nArray after selection sort:");
for(i=0;i<n;i++)
printf("%d ",a[i]);
}