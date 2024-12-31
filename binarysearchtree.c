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

struct Node*findMin(struct Node *root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

struct Node*deleteNode(struct Node *root, int data) {
    if (root == NULL){
        return root;
    }
    else if (data < root->data){
        root->left = deleteNode(root->left, data);
    }
    else if (data > root->data){
        root->right = deleteNode(root->right, data);
    }
    else {
        if (root->left == NULL && root->right == NULL) {
            free(root);
            root = NULL;
        } else if (root->left == NULL) {
            struct Node *temp = root;
            root = root->right;
            free(temp);
        } else if (root->right == NULL) {
            struct Node *temp = root;
            root = root->left;
            free(temp);
        } else {
            struct Node *temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }
    return root;
}

int isBST(struct Node *root) {
    static struct Node*prev=NULL;
    if (root == NULL){
        return 1;
    }
    else{
        if(!isBST(root->left)){
            return 0;
        }
        if(prev!=NULL && root->data<=prev->data){
            return 0;
        }
        prev=root;
        return isBST(root->right);
    }
}

void InOrder(struct Node *root) {
    if (root == NULL) return;
    InOrder(root->left);
    printf("%d ", root->data);
    InOrder(root->right);
}

void main(){
    int choice,data;
    do{
        printf("1. Insert\n2. Delete\n3. InOrder\n4. Exit\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter data to insert: ");
                scanf("%d",&data);
                insert(data);
                break;
            case 2:
                printf("Enter data to delete: ");
                scanf("%d",&data);
                root = deleteNode(root,data);
                break;
            case 3:
                InOrder(root);
                printf("\n");
                break;
            case 4:
                printf("Exiting\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    }while(choice!=4);
    if(isBST(root)){
        printf("It is a BST\n");
    }
    else{
        printf("It is not a BST\n");
    }
}