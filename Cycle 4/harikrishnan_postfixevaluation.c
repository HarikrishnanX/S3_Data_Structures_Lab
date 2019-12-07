#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

#define size 50

char stack[size];
int top=-1;

void push(int item)
{
    if(top>=size-1)
        printf("\nOverflow!");
    else
    {
        top=top+1;
        stack[top]=item;
    }
}

int pop()
{
    int item;
    if(top<0)
    {
        printf("\nUnderflow!");
        getchar();
        exit(1);
    }
    else
    {
        item=stack[top];
        top=top-1;
        return(item);
    }
}

int apply(int o1,int o2,char symb)
{
    int r;
    if(symb=='^')
        r=o1^o2;
    if(symb=='/')
        r=o1/o2;
    if(symb=='*')
        r=o1*o2;
    if(symb=='+')
        r=o1+o2;
    if(symb=='-')
        r=o1-o2;
    return r;
}

int postfix_evaluation(char opndstack[])
{
    int value,op1,op2,result,i,j;
    char item;
    i=0;
    item=opndstack[i];
    while(item!='\0')
    {
        if(isdigit(item))
            push(item - '0');
        else
        {
            op2=pop();
            op1=pop();
            value=apply(op2,op1,item);
            push(value);
        }
        ++i;
        item=opndstack[i];
    }
    result=pop();
    return result;
}

void main()
{
    char postexp[size];
    int val;
    printf("Enter Postfix Expression:");
    gets(postexp);
    val=postfix_evaluation(postexp);
    printf("\nEvaluated value of Postfix Expression:%d",val);
}


