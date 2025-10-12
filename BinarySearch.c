#include <stdio.h>
#include <stdlib.h>

void main()
{
    int arr[5];
    int i,low,mid,high,key,flag=0;
    printf("Read the array elements:\n");
    for(i=0;i<5;i++)
    {
        scanf("%d",&arr[i]);
    }
    low=0;
    high=4;
    mid=low+high/2;
    printf("Enter the key required:\n");
    scanf("%d",&key);

    while(low<=high)
    {
        if(key==arr[mid])
        {
            flag=1;
        }
        if(key>arr[mid])
        {
            low=mid+1;
        }
        if(key<arr[mid])
        {
            high=mid-1;
        }
    }
    if(flag==1)
    {
        printf("Key is found");
    }
    else
    {
        printf("Key not found");
    }
}