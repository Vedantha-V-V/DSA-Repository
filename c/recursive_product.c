#include <stdio.h>

int arr_product(int A[],int arr_length){
    static int count=-1;
    if(count==arr_length-1){
        return 1;
    }
    count++;
    return A[count]*arr_product(A,arr_length);
}

void main(){
    int num,i,pdt;
    printf("Enter the number of elements: ");
    scanf("%d",&num);
    int A[num];
    printf("Enter the array elements:\n");
    for(i=0;i<num;i++){
        scanf("%d",&A[i]);
    }
    pdt=arr_product(A,num);
    printf("%d",pdt);
}