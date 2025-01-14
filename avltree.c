#include <stdio.h>
#include <stdlib.h>

struct Node{
    int info;
    struct Node *left;
    int balfact;
    struct Node *right;
};

int max(int a,int b){
    if(a>b){
        return a;
    }
    else{
        return b;
    }
}

int height(struct Node*root){
    if(root==NULL){
        return -1;
    }
    return (1+max(height(root->left),height(root->right)));
}

struct Node*leftrotate(struct Node*root){
    struct Node*y,*z,*subTree;
    y=root->right;
    z=y->right;
    subTree=y->left;
    y->left=root;
    root->right=subTree;
    root->balfact=height(root->left)-height(root->right);
    y->balfact=height(y->left)-height(y->right);
    return y;
}

struct Node*rightrotate(struct Node*root){
    struct Node*y,*z,*subTree;
    y=root->left;
    z=y->left;
    subTree=y->right;
    y->right=root;
    root->left=subTree;
    root->balfact=height(root->left)-height(root->right);
    y->balfact=height(y->left)-height(y->right);
    return y;
}

struct Node*insert(struct Node*root,int data){
    struct Node*temp;
    int balance;
    if(root==NULL){
        temp=(struct Node*)malloc(sizeof(struct Node));
        temp->info=data;
        temp->right=NULL;
        temp->left=NULL;
        int balfact=0;
        return temp;
    }
    if(data<root->info){
        root->left=insert(root->left,data);
    }
    else if(data>root->info){
        root->right=insert(root->right,data);
    }
    else{
        return root;
    }
    root->balfact=height(root->left)-height(root->right);
    balance=root->balfact;
    if(balance>1 && data<root->left->info){
        return rightrotate(root);
    }
    if(balance<-1 && data>root->left->info){
        return leftrotate(root);
    }
    if(balance>1 && data>root->left->info){
        root->left=leftrotate(root->left);
        return rightrotate(root);
    }
    if(balance<-1 && data<root->right->info){
        root->right=right(root->right);
        return leftrotate(root);
    }
    return root;
}

void main(){
    
}