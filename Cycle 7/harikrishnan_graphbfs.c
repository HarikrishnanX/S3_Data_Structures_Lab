#include<stdio.h>
#include<stdlib.h>

struct node
{
    int dest;
    struct node *next;
};

struct list
{
    struct node *head;
};

struct graph
{
    int v;
    struct list *array;
};

struct node* createnode(int dest)
{
    struct node *newnode;
    newnode=malloc(sizeof(struct node));
    newnode->dest=dest;
    newnode->next=NULL;
    return newnode;
}

struct graph* creategraph(int v)
{
    struct graph *g;
    int i;
    g=malloc(sizeof(struct graph));
    g->v=v;
    g->array=(struct list*)malloc(v*sizeof(struct list));
    for(i=0;i<v;i++)
        g->array[i].head=NULL;
    return g;
}

void addedge(struct graph *g,int src,int dest)
{
    struct node *newnode=createnode(dest);
    newnode->next=g->array[src].head;
    g->array[src].head=newnode;
    newnode=createnode(src);
    newnode->next=g->array[dest].head;
    g->array[dest].head=newnode;
}

void display(struct graph *g)
{
    int v;
    for(v=0;v<g->v;v++)
    {
        struct node *p=g->array[v].head;
        printf("\nAdjacency list of vertex %d\nhead",v);
        while(p)
        {
            printf("->%d",p->dest);
            p=p->next;
        }
        printf("\n");
    }
}

void main()
{
    int v,i,j,s,d,n;
    printf("Enter number of vertices:");
    scanf("%d",&v);
    struct graph *gr=creategraph(v);
    for(i=0;i<v;i++)
    {
        printf("\nEdge %d",i+1);
        printf("\nEnter source vertex:");
        scanf("%d",&s);
        printf("\nEnter number of edges from %d:",s);
        scanf("%d",&n);
        for(j=0;j<n;j++)
        {
            printf("\nEnter vertex %d:",j+1);
            scanf("%d",&d);
            addedge(gr,s,d);
        }
    }
    display(gr);
}