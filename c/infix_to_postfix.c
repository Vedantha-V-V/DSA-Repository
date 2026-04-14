#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define SIZE 100

char stack[SIZE];
int top = -1;

void push(char item)
{
    if(top>=SIZE-1)
    {
        printf("\nStack Overflow");
    }
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
        printf("Stack underflow: invalid infix expression");
        return(0);
    }
    else
    {
        item=stack[top];
        top=top-1;
        return(item);
    }
}

char peek()
{
    char item;
    if(top<0)
    {
        printf("Stack underflow");
        return(0);
    }
    else
    {
        item=stack[top];
        return(item);
    }
}

int precedence(char symbol)
{
    if(symbol=='*'||symbol=='/')
    {
        return(2);
    }
    else if(symbol=='+'||symbol=='-')
    {
        return(1);
    }
    else if(symbol=='(')
    {
        return(0);
    }
    else if(symbol=='#')
    {
        return(-1);
    }
}

void InfixToPostfix(char infix_exp[],char postfix_exp[])
{
    int i,j;
    char item;
    char x;
    push('#');
    i=0;
    j=0;
    item=infix_exp[i];
    while(item!='\0')
    {
        if(isdigit(item)||isalpha(item))
        {
            postfix_exp[j]=item;
            j++;
        }
        else if(item=='(')
        {
            push(item);
        }
        else if(item==')')
        {
            x=pop();
            while(x!='(')
            {
                postfix_exp[j]=x;
                j++;
                x=pop();
            }
        }
        else{
            x=peek();
            while(precedence(x)>=precedence(item)){
                x=pop();
                postfix_exp[j]=x;
                j++;
                x=peek();
            }
            push(item);
        }
        i++;
        item=infix_exp[i];
    }
    while(peek()!='#')
    {
        x=pop();
        postfix_exp[j]=x;
        j++;
    }
    postfix_exp[j]='\0';
}

void main(){
    char infix[SIZE],postfix[SIZE];
    printf("Enter the Infix expression:");
    gets(infix);
    InfixToPostfix(infix,postfix);
    printf("Postfix Expression:");
    puts(postfix);
}