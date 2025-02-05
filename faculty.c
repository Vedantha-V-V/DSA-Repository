#include <stdio.h>
#include <stdlib.h>

struct Node{
    char* name;
    int faculty_id;
    int salary;
};

void add(struct Node* N){
    N->name=(char*)malloc(20*sizeof(char));
    int faculty_id,salary;
    printf("Enter the name: ");
    scanf("%s",N->name);
    printf("Enter the faculty id: ");
    scanf("%d",&N->faculty_id);
    printf("Enter the salary: ");
    scanf("%d",&N->salary);
}

void display(struct Node* N){
    printf("Name: %s\n",N->name);
    printf("Faculty id: %d\n",N->faculty_id);
    printf("Salary: %d\n",N->salary);
}

void main(){
    struct Node*N=(struct Node*)malloc(sizeof(struct Node));
    add(N);
    display(N);
}