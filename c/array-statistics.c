// Program to calculate sum,average and standard deviation using pointers
#include <stdio.h>
#include <math.h>

void main()
{
    int max,i;
    int *p;
    float dev,avg,var,rem,sum=0;
    printf("Enter the maximum limit:");
    scanf("%d",&max);
    int arr[max];
    p=arr;
    printf("Enter the Array Elements:\n");
    for(i=0;i<max;i++)
    {
        scanf("%d",p+i);
    }

    for(i=0;i<max;i++)
    {
        sum+=*(p+i);
    }
    avg=sum/max;
    
    for(i=0;i<max;i++)
    {
        rem=avg - *(p+i);
        var+=pow(rem,2);
    }
    dev=sqrt((var/(max-1)));
    printf("Sum = %d\n",sum);
    printf("Average = %f\n",avg);
    printf("Standard Deviation = %f",dev);
}