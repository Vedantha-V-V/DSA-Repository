#include<stdio.h>
#include<math.h>
void main()
{
    int i=0,num,rem,deci;
    printf("Enter the number in binary:");
    scanf("%d",&num);
    while(num>0)
    {
        rem=num%10;
        deci=deci+(rem*pow(2,i));
        num=num/10;
        i=i+1;
    }
    printf("%d",deci);
}