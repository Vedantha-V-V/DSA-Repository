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

struct Node*findMin(struct Node*root){
    while(root->left!=NULL){
        root=root->left;
    }
    return root;
}

struct Node*delete_node(struct Node*root,int val){
    if(root==NULL){
        return root;
    }
    else if(root->data>val){
        root->left=delete_node(root->left,val);
    }
    else if(root->data<val){
        root->right=delete_node(root->right,val);
    }
    else{
        if(root->left==NULL&&root->right==NULL){
            free(root);
            return NULL;
        }
        else if(root->left=NULL){
            struct Node*temp=root;
            root=root->right;
            free(temp);
        }
        else if(root->right==NULL){
            struct Node*temp=root;
            root=root->left;
            free(temp);
        }
        else{
            struct Node*temp=findMin(root->right);
            root->data=temp->data;
            root->right=delete_node(root->right,temp->data);
        }
    }
    return root;
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