#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node*next;
};
struct Node*head=NULL;
struct Node*head1=NULL;

void traverse(struct Node*root){
    while(root!=NULL){
        printf("%d\t",root->data);
        root=root->next;
    }
    printf("\n");
}

struct Node*getNode(int data){
    struct Node*new_node=(struct Node*)malloc(sizeof(struct Node));
    if(new_node==NULL){
        printf("No memory");
    }
    new_node->data=data;
    new_node->next=NULL;
}

void merge(){
    struct Node*temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=head1;
}

void bubblesort(){
    struct Node*temp,*last;
    int num;
    temp=head;
    last=NULL;
    while(last!=head){
        temp=head;
        while(temp->next!=last){
            if(temp->data>temp->next->data){
                num=temp->data;
                temp->data=temp->next->data;
                temp->next->data=num;
            }
            temp=temp->next;
        }
        last=temp;
    }
}

void main(){
    int i;
    head=getNode(6);
    head1=getNode(1);
    struct Node*temp=head,*temp2=head1;
    for(i=7;i<=9;i++){
        temp->next=getNode(i);
        temp=temp->next;
    }
    for(i=2;i<=5;i++){
        temp2->next=getNode(i);
        temp2=temp2->next;
    }
    traverse(head);
    traverse(head1);
    merge();
    traverse(head);
    bubblesort();
    traverse(head);
}