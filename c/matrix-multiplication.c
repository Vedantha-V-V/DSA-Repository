#include <stdio.h>

void main()
{
    int i,j,k;
    int a[2][2],b[2][2],c[2][2]={0};
    printf("Read elements of a:\n");
    for(i=0;i<2;i++)
    {
        for(j=0;j<2;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }

    printf("Read elements of b:\n");
    for(i=0;i<2;i++)
    {
        for(j=0;j<2;j++)
        {
            scanf("%d",&b[i][j]);
        }
    }

    for(k=0;k<2;k++)
    {
        for(i=0;i<2;i++)
        {
            for(j=0;j<2;j++)
            {
                c[i][j]+=a[i][k]*b[k][j];
            }
        }
    }

    printf("Multiplied Matrix:\n");
    for(i=0;i<2;i++)
    {
        for(j=0;j<2;j++)
        {
            printf("%d\t",c[i][j]);
        }
        printf("\n");
    }
}