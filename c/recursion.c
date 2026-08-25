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

void Toh(int n,char source,char dest,char aux){
    if(n==1){
        printf("Move %d from Tower %c to Tower %c\n",n,source,dest);
        return;
    }
    Toh(n-1,source,aux,dest);
    printf("Move %d form Tower %c to Tower %c\n",n,source,dest);
    Toh(n-1,aux,dest,source);
}

int max_val(int A[],int start,int end){
    int mid=(start+end)/2;
    if(start==mid){
        return A[start];
    }
    int val1=max_val(A,start,mid);
    int val2=max_val(A,mid,end);
    if(val1>val2){
        return val1;
    }
    else{
        return val2;
    }
}

int arr_product(int A[],int arr_length){
    static int count=-1;
    if(count==arr_length-1){
        return 1;
    }
    count++;
    return A[count]*arr_product(A,arr_length);
}

void main(){
    int num,pdt,key;
    Toh(2,'A','C','B');
    printf("Enter the number of elements: ");
    scanf("%d",&num);
    int A[num];
    int i;
    printf("Enter the number of array\n");
    for(i=0;i<5;i++){
        scanf("%d",&A[i]);
    }
    printf("The value in the array is: %d",max_val(A,0,4));
    pdt=arr_product(A,num);
    printf("%d",pdt);
    printf("The minimum value in the array is: %d\n",max_val(A,0,4));
    printf("Enter the key value: ");
    scanf("%d",&key);
    binary_search(A,0,4,key);
}