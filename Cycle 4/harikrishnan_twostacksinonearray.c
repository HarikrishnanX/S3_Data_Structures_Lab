#include<stdio.h>
#include<stdlib.h>

#define size 50

int array[size],s1[size],s2[size];
int top1=-1;
int top2=size;

void push(int x,int stack[])
{
    if(stack==s1)
    {
        if(top1<top2-1)
            array[++top1]=x;
        else
            printf("\nOverflow!");
    }
    else if(stack==s2)
    {
        if(top1<top2-1)
            array[--top2]=x;
        else
            printf("\nOverflow!");
    }
}

void pop(int stack[])
{
    int item;
    if(stack==s1)
    {
        if(top1>=0)
        {
            item=array[top1--];
            printf("\nDeleting element:%d",item);
        }
        else
            printf("\nUnderflow!");
    }
    else if(stack==s2)
    {
        if(top2<size)
        {
            item=array[top2++];
            printf("\nDeleting element:%d",item);
        }
        else
            printf("\nUnderflow!");
    }
}

void display1()
{
    int i;
    if(top1==-1)
        printf("\nStack 1 is empty!");
    else
    {
        printf("\nStack 1:");
        for(i=top1;i>=0;i--)
            printf("%d ",array[i]);
    }
}

void display2()
{
    int i;
    if(top2==size)
        printf("\nStack 2 is empty!");
    else
    {
        printf("\nStack 2:");
        for(i=top2;i<size;i++)
            printf("%d ",array[i]);
    }
}

void main()
{
    int ch,item;
    do
    {
        printf("\nMenu\n1.Push to Stack 1\n2.Push to Stack 2\n3.Pop from Stack 1\n4.Pop from Stack 2\n5.Display Stack 1\n6.Display Stack 2\n7.Exit\nEnter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:printf("\nEnter element:");
                   scanf("%d",&item);
                   push(item,s1);
                   break;
            case 2:printf("\nEnter element:");
                   scanf("%d",&item);
                   push(item,s2);
                   break;
            case 3:pop(s1);
                   break;
            case 4:pop(s2);
                   break;
            case 5:display1();
                   break;
            case 6:display2();
                   break;
            case 7:exit(0);
                   break;
            default:printf("\nInvalid Choice!");
        }
    }while(1);
}
