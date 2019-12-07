#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node* create(int value);
struct node* insert(struct node *root,int data);
struct node* search(struct node *root,int data);
struct node* findmin(struct node *root);
struct node* delete(struct node *root,int data);
void traverse(struct node *root);
void inorder(struct node *root);
void preorder(struct node *root);
void postorder(struct node *root);

struct node* create(int value)
{
    struct node *newnode;
    newnode=malloc(sizeof(struct node));
    newnode->data=value;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}

struct node* insert(struct node *root,int data)
{
    if(root==NULL)
        return create(data);
    if(data<root->data)
        root->left=insert(root->left,data);
    else if(data>root->data)
        root->right=insert(root->right,data);
    return root;
}

struct node* search(struct node *root,int data)
{
    if((root==NULL)||(root->data==data))
        return root;
    else if(data>root->data)
        return search(root->right,data);
    else
        return search(root->left,data);
}

struct node* findmin(struct node *root)
{
    if(root==NULL)
        return NULL;
    else if(root->left!=NULL)
        return findmin(root->left);
    return root;
}

struct node* delete(struct node *root,int data)
{
    if(root==NULL)
        return NULL;
    if(data>root->data)
        root->right=delete(root->right,data);
    else if(data<root->data)
        root->left=delete(root->left,data);
    else
    {
        if((root->right==NULL)&&(root->left==NULL))
        {
            free(root);
            return NULL;
        }
        else if((root->right==NULL)||(root->left==NULL))
        {
            struct node *temp;
            if(root->left==NULL)
                temp=root->right;
            else
                temp=root->left;
            free(root);
            return temp;
        }
        else
        {
            struct node *temp=findmin(root->right);
            root->data=temp->data;
            root->right=delete(root->right,temp->data);
        }
    }
    return root;
}

void traverse(struct node *root)
{
    int ch;
    printf("\nTraversal Menu\n1.Inorder\n2.Preorder\n3.Postorder\nEnter your choice:");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:printf("\nBinary Search Tree:");
               inorder(root);
               break;
        case 2:printf("\nBinary Search Tree:");
               preorder(root);
               break;
        case 3:printf("\nBinary Search Tree:");
               postorder(root);
               break;
        default:printf("\nInvalid Choice!");
    }
}

void inorder(struct node *root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}

void preorder(struct node *root)
{
    if(root!=NULL)
    {
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct node *root)
{
    if(root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
    }
}

void main()
{
    int ch,item;
    struct node *r=NULL;
    do
    {
        printf("\nBinary Search Tree Operations\n1.Insert\n2.Delete\n3.Search\n4.Traversal\n5.Exit\nEnter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:printf("\nEnter element:");
                   scanf("%d",&item);
                   r=insert(r,item);
                   break;
            case 2:printf("\nEnter element to delete:");
                   scanf("%d",&item);
                   r=delete(r,item);
                   break;
            case 3:printf("\nEnter element to search:");
                   scanf("%d",&item);
                   r=search(r,item);
                   if(r==NULL)
                      printf("\nElement not found!");
                   else
                      printf("\nFound Element:%d",r->data);
                   break;
            case 4:traverse(r);
                   break;
            case 5:exit(0);
                   break;
            default:printf("\nInvalid Choice!");
        }
    }while(1);
}
