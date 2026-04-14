#include <stdio.h>
#include <stdlib.h>

struct Node{
    struct Node* left;
    int info;
    struct Node*right;
};

struct Node*root=NULL;

struct Node*getNode(int val){
    struct Node*new_node=(struct Node*)malloc(sizeof(struct Node));
    if(new_node==NULL){
        printf("No memory");
        return 0;
    }
    new_node->left=NULL;
    new_node->right=NULL;
    new_node->info=val;
}

void insert(int val){
    struct Node*temp,*prev;
    if(root==NULL){
        root=getNode(val);
        return;
    }
    temp=root;
    prev=temp;
    while(temp!=NULL){
        prev=temp;
        if(temp->info>val){
            temp=temp->left;
        }
        else{
            temp=temp->right;
        }
    }
    if(prev->info>val){
        prev->left=getNode(val);
    }
    else{
        prev->right=getNode(val);
    }
}

void inorder(struct Node*head){
    if(head!=NULL){
        inorder(head->left);
        printf("%d\t",head->info);
        inorder(head->right);
    }
}

void preorder(struct Node*head){
    if(head!=NULL){
        printf("%d\t",head->info);
        preorder(head->left);
        preorder(head->right);
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
    else if(root->info>val){
        root->left=delete_node(root->left,val);
    }
    else if(root->info<val){
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
            root->info=temp->info;
            root->right=delete_node(root->right,temp->info);
        }
    }
    return root;
}

void main(){
    int val;
    insert(10);
    insert(25);
    insert(5);
    insert(50);
    insert(35);
    inorder(root);
    printf("\n");
    printf("Enter the value to be deleted: ");
    scanf("%d",&val);
    root=delete_node(root,val);
    preorder(root);
}