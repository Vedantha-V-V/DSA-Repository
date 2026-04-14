#include <stdio.h>
#include <stdlib.h>

void main(){
    int *arr;
    int i,n;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    arr=(int*)malloc(n*sizeof(int));
    printf("Enter the elements:\n");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int max=arr[0];
    for(i=0;i<n;i++){
        if(arr[i]>max){
            max=arr[i];
        }
    }
    printf("The maximum number in the array: %d",max);
}