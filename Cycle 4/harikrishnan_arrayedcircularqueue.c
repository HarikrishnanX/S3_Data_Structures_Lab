#include<stdio.h>
#include<stdlib.h>

#define size 50

int queue[size];
int front=-1,rear=-1;

int isfull()
{
    if((front==rear+1)||(front==0&&rear==size-1))
        return 1;
    return 0;
}

int isempty()
{
    if(front==-1)
        return 1;
    return 0;
}

void enqueue(int item)
{
    if(isfull())
        printf("\nOverflow!");
    else
    {
        if(front==-1)
            front=0;
        rear=(rear+1)%size;
        queue[rear]=item;        
    }
}

void dequeue()
{
    int item;
    if(isempty())
        printf("\nUnderflow!");
    else
    {
        item=queue[front];
        if(front==rear)
        {
            front=-1;
            rear=-1;
        }
        else
        {
            front=(front+1)%size;
        }
        printf("\nDeleting element:%d",item);
    }
}

void display()
{
    int i;
    if(isempty())
        printf("\nCircular Queue is empty!");
    else
    {
        printf("\nCircular Queue:");
        for(i=front;i!=rear;i=(i+1)%size)
            printf("%d ",queue[i]);
        printf("%d",queue[i]);
    }
}

void main()
{
    int ch,element;
    do
    {
        printf("\nCircular Queue Operations\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\nEnter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:printf("\nEnter element:");
                   scanf("%d",&element);
                   enqueue(element);
                   break;
            case 2:dequeue();
                   break;
            case 3:display();
                   break;
            case 4:exit(0);
                   break;
            default:printf("\nInvalid choice!");
        }
    }while(1);
}

