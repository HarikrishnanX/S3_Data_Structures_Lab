#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>

#define size 50
char stack[size];
int top=-1;

void push(char item)
{
    if(top>=size-1)
        printf("\nOverflow!");
    else
    {
        top=top+1;
        stack[top]=item;
    }
}

char pop()
{
    char item;
    if(top<0)
    {
        printf("\nUnderrflow!");
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

int isop(char symb)
{
    if((symb=='^')||(symb=='/')||(symb=='*')||(symb=='+')||(symb=='-'))
        return 1;
    else
        return 0;
}

int precedence(char symb)
{
    if(symb=='^')
        return 3;
    else if((symb=='/')||(symb=='*'))
        return 2;
    else if((symb=='+')||(symb=='-'))
        return 1;
    else
        return 0;
}

void infix_to_postfix(char infix[],char postfix[])
{
    int i,j;
    char item,x;
    push('(');
    strcat(infix,")");
    i=0;
    j=0;
    item=infix[i];
    while(item!=NULL)
    {
        if(item=='(')
            push(item);
        else if(isalnum(item))
        {
            postfix[j]=item;
            ++j;
        }
        else if(isop(item)==1)
        {
            x=pop();
            while((isop(x)==1)&&(precedence(x)>=precedence(item)))
            {
                postfix[j]=x;
                ++j;
                x=pop();
            }
            push(x);
            push(item);
        }
        else if(item==')')
        {
            x=pop();
            while(x!='(')
            {
                postfix[j]=x;
                ++j;
                x=pop();
            }

        }
        else
        {
            printf("\nInvalid expression!");
            getchar();
            exit(1);
        }
        ++i;
        item=infix[i];
    }
    if(top>0)
    {
        printf("\nInvalid expression!");
        getchar();
        exit(1);
    }
    postfix[j]='\0';
}

void main()
{
    char inexp[size],postexp[size];
    printf("Enter infix expression:");
    gets(inexp);
    infix_to_postfix(inexp,postexp);
    printf("\nPostfix expression:");
    puts(postexp);
}