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

int calc_parent(struct Node*root){
    if(root==NULL){
        return -1;
    }
    if(root->left==NULL&&root->right==NULL){
        return 0;
    }
    else if(root->right==NULL){
        return 1+calc_parent(root->left);
    }
    else if(root->left==NULL){
        return 1+calc_parent(root->right);
    }
    else{
        return 1+calc_parent(root->left)+calc_parent(root->right);
    }
}

void main(){
    insert(10);
    insert(25);
    insert(5);
    insert(50);
    insert(35);
    inorder(root);
    printf("\n");
    printf("%d",calc_parent(root));
}