#include<stdio.h>

void main()
{
    int dis,i,count=1,temp,max;
    printf("Enter the number of elements: ");
    scanf("%d",&max);
    int arr[max];
    printf("Enter the array elements:\n");
    for(i=0;i<max;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Enter the change in position: ");
    scanf("%d",&dis);
    dis=dis%max;
    while(count<=dis)
    {
        temp=arr[max-1];
        for(i=max-1;i>=0;i--)
        {
            arr[i]=arr[i-1];
        }
        arr[0]=temp;
        count++;
    }
    for(i=0;i<max;i++)
        printf("%d",arr[i]);
}