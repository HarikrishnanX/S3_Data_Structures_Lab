#include<stdio.h>
#include<stdlib.h>

struct node
{
    int info;
    struct node *next;
}*front,*rear;

void main()
{
    struct node *newnode;
    int item,ch;
    while(1)
    {
        printf("\nOperations in Linked Queue\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\nEnter your choice:");
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
                   if(front==NULL)
                      front=rear=newnode;
                   else
                   {
                       rear->next=newnode;
                       rear=newnode;
                   }
                   break;
            case 2:if(front==NULL)
                      printf("\nUnderflow!");
                   else
                   {
                       newnode=front;
                       front=front->next;
                       free(newnode);
                   }
                   break;
            case 3:if(front==NULL)
                   {
                       printf("\nQueue is empty!");
                       break;
                   }
                   printf("\nLinked Queue:");
                   newnode=front;
                   while(newnode!=NULL)
                   {
                       printf("%d->",newnode->info);
                       newnode=newnode->next;
                   }
                   break;
            case 4:exit(0);
            default:printf("\nInvalid Choice!");
        }
    }
}
    
