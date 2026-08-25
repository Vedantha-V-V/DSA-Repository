#include<stdio.h>
void main()
{
    int i,j,k;
    int num=10;
    for(i=1;i<=num;i++)
    {
        for(j=1;j<=num-i;j++)
        {
            printf(" ");
        }
        int coef=1;
        for(k=1;k<=i;k++)
        {
            printf("%d\t",coef);
            coef=coef*(i-k)/k;
        }
        printf("\n");
    }
}