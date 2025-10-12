#include <stdio.h>
#include <string.h>

char A[10];

int top=-1;

void reverse(char *strin)
{
    int i=0;
    while(strin[i]!='\0')
    {
        top+=1;
        A[top]=strin[i];
        i++;
    }
    A[top]='\0';
}

char pop()
{
    if(top==-1)
    {
        return '\0';
    }
    char temp=A[top];
    top-=1;
    return temp;
}


void main()
{
    int i;
    char str[10];
    printf("Enter the string:");
    scanf("%s",str);
    reverse(str);
    printf("Reversed String:");
    for(i=0;i<strlen(str);i++)
    {
        printf("%c",pop());
    }
}