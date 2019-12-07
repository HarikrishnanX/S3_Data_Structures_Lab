#include<stdio.h>
#include<stdlib.h>

struct node
{
    int info;
    struct node *next;
}*top,*ptr;

void main()
{
    struct node *newnode;
    top=NULL;
    int ch,item;
    while(1)
    {
        printf("\nOperations in Linked Stack\n1.Push\n2.Pop\n3.Display\n4.Exit\nEnter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:newnode=malloc(sizeof(struct node));
                   if(newnode==NULL)
                   {
                       printf("\nOverflow");
                       break;
                   }
                   printf("\nEnter element:");
                   scanf("%d",&item);
                   newnode->info=item;
                   newnode->next=NULL;
                   if(top==NULL)
                       top=newnode;
                   else
                   {
                       newnode->next=top;
                       top=newnode;
                   }
                   break;
            case 2:if(top==NULL)
                       printf("\nUnderflow");
                   else
                   {
                       ptr=top;
                       printf("\nDeleting %d",top->info);
                       top=top->next;
                       free(ptr);
                   }
                   break;
            case 3:printf("\nStack:");
                   ptr=top;
                   if(top==NULL)
                   {
                       printf("\nStack is empty!");
                       break;
                   }
                   while(ptr!=NULL)
                   {
                       printf("%d->",ptr->info);
                       ptr=ptr->next;
                   }
                   break;
            case 4:exit(0);
            default:printf("\nInvalid Choice!");
        }
    }
}