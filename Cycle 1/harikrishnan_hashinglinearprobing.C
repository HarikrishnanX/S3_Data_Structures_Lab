#include<stdio.h>
int m=13;
int hash(int key)
{int i;
i=key%m;
return i;
}
int rehash(int key)
{int i;
i=(key+1)%m;
return i;
}
void main()
{int k,h[20],a[20],n,i,j;
printf("Enter number of elements:");
scanf("%d",&n);
printf("\nEnter elements:");
for(i=0;i<n;i++)
scanf("%d",&a[i]);
for(i=0;i<m;i++)
h[i]=0;
for(j=0;j<n;j++)
{k=a[j];
i=hash(k);
while(h[i]!=0)
{i=rehash(i);
}
h[i]=k;
}
printf("\nFinal hash table:");
for(i=0;i<m;i++)
printf("\nElement at index %d:%d",i,h[i]);
}

