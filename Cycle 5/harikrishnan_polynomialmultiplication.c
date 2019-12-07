#include<stdio.h>
#include<stdlib.h>

struct poly
{
    int coef;
    int exp;
    struct poly *link;
};

struct poly* insert(struct poly *start,int coeff,int power)
{
    struct poly *newnode,*p;
    newnode=malloc(sizeof(struct poly));
    newnode->coef=coeff;
    newnode->exp=power;
    newnode->link=NULL;
    if(start==NULL)
        return newnode;
    p=start;
    while(p->link!=NULL)
        p=p->link;
    p->link=newnode;
    return start;
}

void removedupe(struct poly *start)
{
    struct poly *p1,*p2,*d;
    p1=start;
    while((p1!=NULL)&&(p1->link!=NULL))
    {
        p2=p1;
        while(p2->link!=NULL)
        {
            if(p1->exp==p2->link->exp)
            {
                p1->coef=(p1->coef)+(p2->link->coef);
                d=p2->link;
                p2->link=p2->link->link;
                free(d);
            }
            else
                p2=p2->link;
        }
        p1=p1->link;
    }
}

void display(struct poly *ptr)
{
    while(ptr->link!=NULL)
    {
        printf("%dx^%d",ptr->coef,ptr->exp);
        if(ptr->link!=NULL)
            printf("+");
        ptr=ptr->link;
    }
    printf("%dx^%d",ptr->coef,ptr->exp);
}

struct poly* multiply(struct poly *a,struct poly *b,struct poly *c)
{
    struct poly *p,*p1,*p2;
    int co,pow;
    p1=a;
    p2=b;
    while(p1!=NULL)
    {
        while(p2!=NULL)
        {
            co=(p1->coef)*(p2->coef);
            pow=(p1->exp)+(p2->exp);
            c=insert(c,co,pow);
            p2=p2->link;
        }
        p2=b;
        p1=p1->link;
    }
    removedupe(c);
    return c;
}

void main()
{
    struct poly *r=NULL,*p=NULL,*q=NULL;
    int c1,c2,e1,e2,n1,n2,i;
    printf("Enter number of terms in Polynomial 1:");
    scanf("%d",&n1);
    for(i=0;i<n1;i++)
    {
        printf("\nTerm %d:",i+1);
        printf("\nCoefficient:");
        scanf("%d",&c1);
        printf("\nPower:");
        scanf("%d",&e1);
        p=insert(p,c1,e1);
    }
    printf("\nEnter number of terms in Polynomial 2:");
    scanf("%d",&n2);
    for(i=0;i<n2;i++)
    {
        printf("\nTerm %d:",i+1);
        printf("\nCoefficient:");
        scanf("%d",&c2);
        printf("\nPower:");
        scanf("%d",&e2);
        q=insert(q,c2,e2);
    }
    printf("\nPolynomial 1:");
    display(p);
    printf("\nPolynomial 2:");
    display(q);
    r=multiply(p,q,r);
    printf("\nResultant Polynomial after Multiplication:");
    display(r);
}