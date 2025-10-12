#include <iostream>
using namespace std;

void select(int a[],int n){
    int temp,min,i,j;
    for(i=0;i<n-1;i++){
        min=i;
        for(j=i+1;j<n;j++){
            if(a[j]<a[min]){
                min=j;
            }
        }
        temp=a[i];
        a[i]=a[min];
        a[min]=temp;
    }
    cout << "\nSorted array: ";
    for(int i=0;i<n;i++){
        cout << a[i] << " ";
    }
}

int main(){
    int arr[6] = {20,5,1,25,30,12};
    select(arr,6);
    return 0;
}