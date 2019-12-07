#include<stdio.h>
#include<stdlib.h>

const int size=50;

void main()
{
    int stack[size],item,top=-1,ch,i;
    while(1)
    {
        printf("\nOperations in Arrayed Stack\n1.Push\n2.Pop\n3.Display\n4.Exit\nEnter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:if(top==-1)
                   top=0;
                   else if(top==size-1)
                   {
                       printf("\nOverflow");
                       break;
                   }
                   else
                   top++;
                   printf("\nEnter element:");
                   scanf("%d",&item);
                   stack[top]=item;
                   break;
            case 2:if(top==-1)
                   printf("\nUnderflow");
                   else if(top==0)
                   top=-1;
                   else
                   top--;
                   break;
            case 3:printf("\n");
                   for(i=top;i>=0;i--)
                   printf("%d ",stack[i]);
                   break;
            case 4:exit(0);
                   break;
            default:printf("\nInvalid Choice!");
        }
    }
}