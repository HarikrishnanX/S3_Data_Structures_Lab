#include<stdio.h>
#include<stdlib.h>

const int size=50;

void main()
{
    int queue[size],item,front=-1,rear=-1,ch,i;
    while(1)
    {
        printf("\nOperations in Arrayed Queue\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\nEnter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:printf("\nEnter element:");
                   scanf("%d",&item);
                   if(rear==size-1)
                      printf("\nOverflow!");
                   else if(rear==-1)
                   {
                       front=rear=0;
                       queue[rear]=item;
                   }
                   else
                   {
                       rear++;
                       queue[rear]=item;
                   }
                   break;
            case 2:if(rear==-1)
                      printf("\nUnderflow");
                   else if(front==rear)
                      front=rear=-1;
                   else
                      front++;
                   break;
            case 3:if(front==-1)
                   {
                       printf("\nQueue is empty!");
                       break;
                   }
                   printf("\nArrayed Queue:");
                   for(i=front;i<rear;i++)
                      printf("%d ",queue[i]);
                   printf("%d",queue[rear]);
                   break;
            case 4:exit(0);
            default:printf("\nInvalid Choice!");
        }
    }
}