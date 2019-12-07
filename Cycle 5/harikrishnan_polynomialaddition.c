#include<stdio.h>
#include<stdlib.h>

struct poly1
{
    int coef1;
    int exp1;
    struct poly1 *link1;
}*start1=NULL;

struct poly2
{
    int coef2;
    int exp2;
    struct poly2 *link2;
}*start2=NULL;

struct poly
{
    int coef;
    int exp;
    struct poly *link;
}*start=NULL;

void main()
{
    int c3,c1,c2,e1,e2,n1,n2,i;
    struct poly *c,*t;
    struct poly1 *a,*t1;
    struct poly2 *b,*t2;
    printf("Enter number of terms in Polynomial 1:");
    scanf("%d",&n1);
    for(i=0;i<n1;i++)
    {
        a=malloc(sizeof(struct poly1));
        printf("\nTerm %d:",i+1);
        printf("\nCoefficient:");
        scanf("%d",&c1);
        printf("\nPower:");
        scanf("%d",&e1);
        a->coef1=c1;
        a->exp1=e1;
        a->link1=NULL;
        if(start1==NULL)
            start1=a;
        else
        {
            t1=start1;
            while(t1->link1!=NULL)
                t1=t1->link1;
            t1->link1=a;
        }
    }
    printf("\nEnter number of terms in Polynomial 2:");
    scanf("%d",&n2);
    for(i=0;i<n2;i++)
    {
        b=malloc(sizeof(struct poly2));
        printf("\nTerm %d:",i+1);
        printf("\nCoefficient:");
        scanf("%d",&c2);
        printf("\nPower:");
        scanf("%d",&e2);
        b->coef2=c2;
        b->exp2=e2;
        b->link2=NULL;
        if(start2==NULL)
            start2=b;
        else
        {
            t2=start2;
            while(t2->link2!=NULL)
                t2=t2->link2;
            t2->link2=b;
        }
    }
    t1=start1;
    printf("\nPolynomail 1:");
    while(t1!=NULL)
    {
        printf("%dx^%d",t1->coef1,t1->exp1);
        if(t1->link1!=NULL)
            printf("+");
        t1=t1->link1;
    }
    t2=start2;
    printf("\nPolynomial 2:");
    while(t2!=NULL)
    {
        printf("%dx^%d",t2->coef2,t2->exp2);
        if(t2->link2!=NULL)
            printf("+");
        t2=t2->link2;
    }
    t1=start1;
    t2=start2;
    while((t1!=NULL)&&(t2!=NULL))
    {
        c=malloc(sizeof(struct poly));
        if((t1->exp1)==(t2->exp2))
        {
            c3=(t1->coef1)+(t2->coef2);
            c->coef=c3;
            c->exp=t1->exp1;
            c->link=NULL;
            t1=t1->link1;
            t2=t2->link2;
        }
        else if((t1->exp1)>(t2->exp2))
        {
            c->coef=t1->coef1;
            c->exp=t1->exp1;
            c->link=NULL;
        }
        else
        {
            c->coef=t2->coef2;
            c->exp=t2->exp2;
            c->link=NULL;
        }
        if(start==NULL)
            start=c;
        else
        {
            t=start;
            while(t->link!=NULL)
                t=t->link;
            t->link=c;
        }
    }
    while(t1!=NULL)
    {
        c=malloc(sizeof(struct poly));
        c->coef=t1->coef1;
        c->exp=t1->exp1;
        c->link=NULL;
        if(start==NULL)
            start=c;
        else
        {
            t=start;
            while(t->link!=NULL)
                t=t->link;
            t->link=c;
        }
    }
    while(t2!=NULL)
    {
        c=malloc(sizeof(struct poly));
        c->coef=t2->coef2;
        c->exp=t2->exp2;
        c->link=NULL;
        if(start==NULL)
            start=c;
        else
        {
            t=start;
            while(t->link!=NULL)
                t=t->link;
            t->link=c;
        }
    }
    printf("\nResultant Polynomail after Addition:");
    t=start;
    while(t!=NULL)
    {
        printf("%dx^%d",t->coef,t->exp);
        if(t->link!=NULL)
            printf("+");
        t=t->link;
    }
}