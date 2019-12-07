#include<stdio.h>
int n,k=1;
void mergesort(int a[],int first,int last);
void merge(int x[],int ft,int m,int lt);
void main()
{int ar[10],f,l,i;
printf("Enter size:");
scanf("%d",&n);
f=0;
l=n-1;
printf("\nEnter elements:");
for(i=0;i<n;i++)
scanf("%d",&ar[i]);
mergesort(ar,f,l);
printf("\nArray after mergesort:");
for(i=0;i<n;i++)
printf("%d ",ar[i]);
}
void mergesort(int a[],int first,int last)
{int mid;
if(first==last)
return;
else
{mid=(first+last)/2;
mergesort(a,first,mid);
mergesort(a,mid+1,last);
merge(a,first,mid,last);
}
}
void merge(int x[],int ft,int m,int lt)
{int j,lpt,upt,size,b[20];
j=0;
lpt=ft;
upt=m+1;
size=lt-ft+1;
while(lpt<m+1&&upt<lt+1)
{if(x[lpt]<x[upt])
{b[j]=x[lpt];
lpt=lpt+1;
j=j+1;
}
else
{b[j]=x[upt];
upt=upt+1;
j=j+1;
}
}
while(lpt<m+1)
{b[j]=x[lpt];
j=j+1;
lpt=lpt+1;
}
while(upt<lt+1)
{b[j]=x[upt];
j=j+1;
upt=upt+1;
}
lpt=ft;
for(j=0;j<size;j++)
{x[lpt]=b[j];
lpt=lpt+1;
}
printf("\nArray after merge %d:",k);
for(j=0;j<n;j++)
printf("%d ",x[j]);
k=k+1;
}