#include <stdio.h>
#include <string.h>

void binary_search(int A[],int start,int end,int key){
    int mid=(start+end)/2;
    if(start==mid){
        printf("Key not found");
        return;
    }
    if(key>A[mid]){
        binary_search(A,mid,end,key);
    }
    else if(key<A[mid]){
        binary_search(A,start,mid,key);
    }
    else{
        printf("Key found at %d",mid);
    }
}

int max_val(int A[],int start,int end){
    int mid=(start+end)/2;
    if(start==mid){
        return A[start];
    }
    int val1=max_val(A,start,mid);
    int val2=max_val(A,mid,end);
    if(val1<val2){
        return val1;
    }
    else{
        return val2;
    }
}

void main(){
    int A[5];
    int i,key;
    printf("Enter the number of array\n");
    for(i=0;i<5;i++){
        scanf("%d",&A[i]);
    }
    printf("The minimum value in the array is: %d\n",max_val(A,0,4));
    printf("Enter the key value: ");
    scanf("%d",&key);
    binary_search(A,0,4,key);
}