#include <stdio.h>

void swap_call_by_value(int x, int y);
void swap_call_by_reference(int *ptrx, int *ptry);

int main()
{
    int x,y;
    printf("Read values of x and y:");
    scanf("%d%d",&x,&y);
    swap_call_by_value(x, y);
    swap_call_by_reference(&x, &y);
    return 0;
}

void swap_call_by_value(int x, int y)
{
    int temp;
    temp=x;
    x=y;
    y=temp;
    printf("After swapping with call by value x: %d and y: %d\n",x,y);
}

void swap_call_by_reference(int *ptrx, int *ptry)
{
    int temp;
    temp=*ptrx;
    *ptrx=*ptry;
    *ptry=temp;
    printf("After swapping with call by reference x: %d and y: %d\n",*ptrx, *ptry);
}