#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *link;
}*start=NULL,*end=NULL;

void insert();
void delete();
void display();

void insert()
{
    struct node *newnode;
    int item;
    printf("\nEnter item:");
    scanf("%d",&item);
    newnode=malloc(sizeof(struct node));
    newnode->data=item;
    newnode->link=NULL;
    if(end==NULL)
        start=end=newnode;
    else
    {
        end->link=newnode;
        end=newnode;
    }
    end->link=start;
}

void delete()
{
    struct node *temp;
    temp=start;
    if(start==NULL)
        printf("\nCircular Linked List is empty!");
    else
    {
        if(start==end)
        {
            printf("\nDeleting Node with Data Value:%d",start->data);
            start=end=NULL;
        }
        else
        {
            printf("\nDeleting Node with Data Value:%d",start->data);
            start=start->link;
            end->link=start;
        }
        temp->link=NULL;
        free(temp);
    }
}

void display()
{
    struct node *temp;
    temp=start;
    if(start==NULL)
        printf("\nCircular Linked List is empty!");
    else
    {
        printf("\nCircular Linked List:");
        while(temp!=end)
        {
            printf("%d->",temp->data);
            temp=temp->link;
        }
        printf("%d->",temp->data);
    }
}
      
void main()
{
    int ch;
    do
    {
        printf("\nCircular Linked List Operations\n1.Insert\n2.Delete\n3.Display\n4.Exit\nEnter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:insert();
                   break;
            case 2:delete();
                   break;
            case 3:display();
                   break;
            case 4:exit(0);
                   break;
            default:printf("\nInvalid Choice!");
        }
    }while(1);
}
    
