#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *link;
}*start=NULL;

void main()
{
    struct node *temp,*newnode,*prev,*next;
    int n,i,item;
    printf("Enter number of nodes:");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("\nEnter node %d:",i+1);
        scanf("%d",&item);
        newnode=malloc(sizeof(struct node));
        newnode->data=item;
        newnode->link=NULL;
        if(start!=NULL)
            newnode->link=start;
        start=newnode;
    }
    printf("\nOriginal Linked List:");
    if(start!=NULL)
    {          
        temp=start;
        while(temp!=NULL)
        {
            printf("%d->",temp->data);
            temp=temp->link;
        }
    }
    printf("\nReversed Linked List:");
    temp=start;
    prev=NULL;
    next=NULL;
    while(temp!=NULL)
    {
        next=temp->link;
        temp->link=prev;
        prev=temp;
        temp=next;
    }
    start=prev;
    temp=start;
    while(temp!=NULL)
    {
        printf("%d->",temp->data);
        temp=temp->link;
    }
}
    
    
