#include<stdio.h>
#include<math.h>
void main()
{
    int i=0,j,num,rem;
    int b[10]={0};
    printf("Enter the number: ");
    scanf("%d",&num);
    rem=num;
    
    while(rem>0)
    {
        b[i]=rem%2;
        rem=rem/2;
        i+=1;
    }

    for(j=i-1;j>=0;j--)
    {
        printf("%d",b[j]);
    }
}