#include<stdio.h>
#include<stdbool.h>
void main()
{
    int i=0,num,rem,deci;
    int isP=1;
    printf("Enter the number:");
    scanf("%d",&num);
    for(i=2;i<num;i++)
    {
        if(num%i==0)
        {
            isP=0;
        }
    }
    if(isP==1)
    {
        printf("The number %d is a prime number",num);
    }
    else
    {
        printf("The number %d is not a prime number.",num);
    }
}