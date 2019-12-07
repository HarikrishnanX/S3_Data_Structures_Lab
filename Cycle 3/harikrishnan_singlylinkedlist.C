#include<stdio.h>
#include<stdlib.h>
struct node
{int data;
struct node *link;
}*start=NULL;
void insert(void);
void delete(void);
void display(void);
void insertbeg(int item);
void insertend(int item);
void insertpos(int item,int val);
void insert()
{int ch,item,val;
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
{struct node *temp,*prev;
int item,c=0;
printf("\nEnter data to be deleted:");
scanf("%d",&item);
if(start!=NULL)
{temp=start;
while((temp->link!=NULL)&&(temp->data!=item))
{prev=temp;
temp=temp->link;
c++;
}
if(c==0)
start=temp->link;
else
prev->link=temp->link;
free(temp);
printf("\nDeleted node with data value:%d",item);
}
else
printf("\nLinked List is empty!");
}
void display()
{struct node *temp;
printf("\nLinked List:");
temp=start;	
if(start!=NULL)
{while(temp->link!=NULL)
{
printf("%d->",temp->data);
temp=temp->link;
}
printf("%d->",temp->data);
}
else
printf("\nLinked List is empty!");
}
void insertbeg(int item)
{struct node *newnode;
newnode=malloc(sizeof(struct node));
newnode->data=item;
newnode->link=NULL;
if(start!=NULL)
newnode->link=start;
start=newnode;
}
void insertend(int item)
{struct node *newnode,*temp;
newnode=malloc(sizeof(struct node));
newnode->data=item;
newnode->link=NULL;
temp=start;
while(temp->link!=NULL)
temp=temp->link;
temp->link=newnode;	
}
void insertpos(int item,int val)
{struct node *newnode,*temp;
int i;	
newnode=malloc(sizeof(struct node));
newnode->data=item;
newnode->link=NULL;
if(start!=NULL)
{temp=start;
while(temp->link!=NULL)
{
if(temp->data==val)
{newnode->link=temp->link;
temp->link=newnode;
break;
}
temp=temp->link;
}
}
}
void main()
{int ch;
do
{printf("\nLinked List Operations\n1.Insert\n2.Delete\n3.Display\n4.Exit\nEnter your choice:");
scanf("%d",&ch);
switch(ch)
{case 1:insert();
    	break;
case 2:delete();
       break;
case 3:display();
       break;
case 4:exit(0);
       break;
default:printf("\nInvalid Choice!");
    	break;
}
}while(1);
}
