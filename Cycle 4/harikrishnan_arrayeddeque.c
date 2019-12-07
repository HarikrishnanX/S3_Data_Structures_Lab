#include<stdio.h>

#define size 50
int deque[size];
int front=-1;
int rear=-1;

void insertrear()
{
    int item;
    if((front==0&&rear==size-1)||(front==rear+1))
    {
        printf("\nOverflow!");
        return;
    }
    if(front==-1)
    {
        front=0;
        rear=0;
    }
    else if(rear==size-1)
        rear=0;
    else
        rear=rear+1;
    printf("\nEnter element:");
    scanf("%d",&item);
    deque[rear]=item;
}

void insertfront()
{
    int item;
    if((front==0&&rear==size-1)||(front==rear+1))
    {
        printf("\nOverflow!");
        return;
    }
    if(front==-1)
    {
        front=0;
        rear=0;
    }
    else if(front==0)
        front=size-1;
    else
        front=front-1;
    printf("\nEnter element:");
    scanf("%d",&item);
    deque[front]=item;
}

void deleterear()
{
    if(front==-1)
    {
        printf("\nUnderflow!");
        return;
    }
    printf("\nDeleting element:%d",deque[rear]);
    if(front==rear)
    {
        front=-1;
        rear=-1;
    }
    else if(rear==0)
        rear=size-1;
    else
        rear=rear-1;
}

void deletefront()
{
    if(front==-1)
    {
        printf("\nUnderflow!");
        return;
    }
    printf("\nDeleting element:%d",deque[front]);
    if(front==rear)
    {
        front=-1;
        rear=-1;
    }
    else if(front==size-1)
        front=0;
    else
        front=front+1;
}

void display()
{
    int f,r;
    f=front;
    r=rear;
    if(front==-1)
    {
        printf("\nDeque is empty!");
        return;
    }
    printf("\nDeque:");
    if(f<=r)
    {
        while(f<=r)
        {
            printf("%d ",deque[f]);
            f++;
        }
    }
    else
    {
        while(f<=size-1)
        {
            printf("%d ",deque[f]);
            f++;
        }
        f=0;
        while(f<=r)
        {
            printf("%d ",deque[f]);
            f++;
        }
    }
}

void input()
{
    int ch;
    do
    {
        printf("\n1.Insert at rear\n2.Delete from rear\n3.Delete from front\n4.Display\n5.Exit\nEnter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:insertrear();
                   break;
            case 2:deleterear();
                   break;
            case 3:deletefront();
                   break;
            case 4:display();
                   break;
            case 5:break;
            default:printf("\nInvalid Choice!");
        }
    }while(ch!=5);
}

void output()
{
    int ch;
    do
    {
        printf("\n1.Insert at front\n2.Insert at rear\n3.Delete from front\n4.Display\n5.Exit\nEnterr your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:insertfront();
                   break;
            case 2:insertrear();
                   break;
            case 3:deletefront();
                   break;
            case 4:display();
                   break;
            case 5:break;
            default:printf("\nInvalid Choice!");
        }
    }while(ch!=5);
}

void main()
{
    int ch;
    printf("\nDeque Menu\n1.Input Restricted Deque\n2.Output Restricted Deque\nEnter your choice:");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:input();
               break;
        case 2:output();
               break;
        default:printf("\nInvalid Choice!");
    }
}

