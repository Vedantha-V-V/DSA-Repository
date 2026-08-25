#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int queue[MAX];
int front=-1;
int rear=-1;

void enqueue(int num){
    if(front==rear+1||(front==0&&rear>=MAX-1)){
        printf("Queue Overflow\n");
        return;
    }
    rear=(rear+1)%MAX;
    queue[rear]=num;
    printf("%d\n",front);
    if(front==-1){
        front++;
    }
}

int dequeue(){
    if(front==-1){
        printf("Queue Underflow\n");
        return 0;
    }
    int temp=queue[front];
    if(front==rear){
        front=rear=-1;
    }
    front=(front+1)%MAX;
    return temp;
}

void display(){
    int i;
    if(front==-1){
        printf("Queue Empty:");
        return;
    }
    for(i=front;i!=rear;i=(i+1)%MAX){
        printf("%d\t",queue[i]);
    }
}

void main(){
    int choice,num;
    printf("1.Enqueue 2.Dequeue 3.Display 4.Exit\n");
    do{
        printf("Enter the choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:

            printf("Enter the number: ");
            scanf("%d",&num);
            enqueue(num);
            break;
            case 2:
            printf("The number removed: %d\n",dequeue());
            break;
            case 3:
            display();
            printf("\n");
            break;
            case 4:
            printf("Exiting...");
            break;
            default:
            printf("Invalid choice");
        }
    }while(choice!=4);
}