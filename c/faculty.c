#include <stdio.h>
#include <stdlib.h>

struct Node{
    char* name;
    int faculty_id;
    int salary;
};

void add(struct Node* N,int n){
    int i;
    for(i=0;i<n;i++){
        N[i].name=(char*)malloc(20*sizeof(char));
        printf("Enter the name: ");
        scanf("%s",N[i].name);
        printf("Enter the faculty id: ");
        scanf("%d",&N[i].faculty_id);
        printf("Enter the salary: ");
        scanf("%d",&N[i].salary);
    }
}

void display(struct Node* N,int n){
    for(int i=0;i<n;i++){
        printf("Name: %s\n",N[i].name);
        printf("Faculty id: %d\n",N[i].faculty_id);
        printf("Salary: %d\n",N[i].salary);
    }
}

void main(){
    int n;
    printf("Enter the number of faculty: ");
    scanf("%d",&n);
    struct Node*N=(struct Node*)malloc(n*sizeof(struct Node));
    add(N,n);
    display(N,n);
}