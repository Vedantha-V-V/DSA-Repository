#include <stdio.h>
#include <stdlib.h>
#define MAX 100

struct Node{
    int val;
    struct Node*next;
};

struct Node*arrList[4];
int check[4];
int queue[MAX];
int front = -1;
int rear = -1;

int dequeue(){
    int val=queue[front];
    front++;
    return val;
}

int peek(){
    if(front==-1){
        return 0;
    }
    return queue[front];
}

void enqueue(int val){
    rear+=1;
    queue[rear]=val;
    if(front==-1){
        front=0;
    }
}

struct Node*getNode(int val){
    struct Node*new_node=(struct Node*)malloc(sizeof(struct Node));
    new_node->val=val;
    new_node->next=NULL;
}

void createList(){
    int n,i,j,nod;
    for(i=0;i<5;i++){
        printf("Enter the number of connected nodes:");
        scanf("%d",&n);
        struct Node*head=NULL;
        struct Node*temp=NULL;
        for(j=0;j<n;j++){
            printf("Enter the connected node:");
            scanf("%d",&nod);
            if(head==NULL){
                head=getNode(nod);
                arrList[i]=head;
                temp=head;
            }
            else{
                temp->next=getNode(nod);
                temp=temp->next;
            }
        }
        check[i]=0;
    }
}

void BreadthFirst(){
    enqueue(0);
    while(front<=rear){
        struct Node*temp=arrList[peek()];
        while(temp!=NULL){
            int value=temp->val;
            if(check[value]==0){
                enqueue(value);
                check[value]=1;
            }
            temp=temp->next;
        }
        int val=dequeue();
        printf("%d\t",val);
    }
}

void main(){
    int i;
    createList();
    for(i=0;i<5;i++){
        struct Node*temp=arrList[i];
        printf("%d\t",i);
        while(temp!=NULL){
            printf("->%d",temp->val);
            temp=temp->next;
        }
        printf("\n");
    }
    BreadthFirst();
}