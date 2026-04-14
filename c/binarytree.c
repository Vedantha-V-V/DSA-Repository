#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node*root = NULL;

struct Node* createNode(int data) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void insert(int data) {
    struct Node*newNode = createNode(data);
    struct Node*temp,*prev;
    if (root == NULL) {
        root = newNode;return;
    } 
    temp = root;
    while(temp!=NULL){
        prev = temp;
        if(data<temp->data){
            temp = temp->left;
        }
        else{
            temp = temp->right;
        }
    }
    if(prev->data>data){
        prev->left = createNode(data);
    }
    else{
        prev->right = createNode(data);
    }
}

void Inorder(struct Node *root) {
    if (root != NULL){
        Inorder(root->left);
        printf("%d ", root->data);
        Inorder(root->right);
    } 
}

void Kthelement(struct Node*root,int val){
    struct Node*stack[100];
    struct Node*current=root;
    int top=-1;
    int rear=-1;
    int queue[100];
    while(current!=NULL||top>=0){
        while(current!=NULL){
            stack[++top]=current;
            current=current->left;
        }
        current=stack[top--];
        queue[++rear]=current->data;
        current=current->right;
    }
    if(val<=rear){
        printf("%d\n",queue[val-1]);
    }
    else{
        printf("No such element\n");
    }
}

void main(){
    int choice,data;
    do{
        printf("1. Insert\n2. InOrder\n3. Exit\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter data to insert: ");
                scanf("%d",&data);
                insert(data);
                break;
            case 2:
                Inorder(root);
                printf("\n");
                Kthelement(root,2);
                break;
            case 3:
            printf("Exiting\n");
            break;
            default:
            printf("Invalid choice\n");
                break;
        }
    }while(choice!=3);
}