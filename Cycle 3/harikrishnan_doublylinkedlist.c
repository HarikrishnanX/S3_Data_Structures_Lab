#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
}*start=NULL;

void insert(void);
void delete(void);
void display(void);
void insertbeg(int item);
void insertend(int item);
void insertpos(int item,int val);

void insert()
{
    int ch,item,val;
    printf("\nInsertion Menu\n1.Insert at beginning\n2.Insert at end\n3.Insert after particular node\nEnter your choice:");
    scanf("%d",&ch);
    printf("\nEnter item:");
    scanf("%d",&item);
    switch(ch)
    {case 1:insertbeg(item);
    	    break;
    case 2:insertend(item);
           break;
    case 3:printf("\nEnter node after which element should be inserted:");
           scanf("%d",&val);
           insertpos(item,val);
           break;
    default:printf("\nInvalid Choice!");
    }
}

void delete()   
{
    struct node *temp;
    int item;
    printf("\nEnter Node to delete:");
    scanf("%d",&item);
    if(start!=NULL)
    {
        temp=start;
        while(temp!=NULL)
        {
            if(temp->data==item)
                break;
            temp=temp->right;
        }
        if(start==temp)
            start=temp->right;
        if(temp->right!=NULL)
            temp->right->left=temp->left;
        if(temp->left!=NULL)
            temp->left->right=temp->right;
        free(temp);
        printf("\nDeleted Node with Data Value:%d",item);
    }
    else
        printf("\nDoubly Linked List is empty!");
}

void display()
{
    struct node *temp;
    printf("\nDoubly Linked List:");
    temp=start;	
    if(start!=NULL)
    {
        while(temp!=NULL)
        {  
            printf("%d->",temp->data);
            temp=temp->right;
        }   
    }   
    else
        printf("\nDoubly Linked List is empty!");
}

void insertbeg(int item)
{
    struct node *newnode;
    newnode=malloc(sizeof(struct node));
    newnode->data=item;
    newnode->left=NULL;
    newnode->right=NULL;
    newnode->right=start;        
    start=newnode->left;
    if(start!=NULL)
        start->left=newnode->right;
    start=newnode;
}

void insertend(int item)
{
    struct node *newnode,*temp;
    newnode=malloc(sizeof(struct node));
    temp=start;
    newnode->data=item;
    newnode->right=NULL;
    if(start==NULL)
    {
        newnode->left=NULL;
        start=newnode;
        return;
    }
    while(temp->right!=NULL)
        temp=temp->right;
    temp->right=newnode;
    newnode->left=temp;
}

void insertpos(int item,int val)
{
    struct node *newnode,*temp;
    newnode=malloc(sizeof(struct node));
    newnode->data=item;
    newnode->right=NULL;
    temp=start;
    while(temp!=NULL)
    {
        if(temp->data==val)
            break;
        temp=temp->right;
    }
    newnode->right=temp->right;
    temp->right=newnode;
    newnode->left=temp;
    if(newnode->right!=NULL)
        newnode->right->left=newnode;
}
    
void main()
{
    int ch;
    do
    {
        printf("\nDoubly Linked List Operations\n1.Insert\n2.Delete\n3.Display\n4.Exit\nEnter your choice:");
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
