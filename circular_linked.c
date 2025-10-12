#include <stdio.h>
#include <stdlib.h>

struct Node{
    int info;
    struct Node*next;
};

struct Node*last=NULL;

struct Node*getNode(int p)
{
    struct Node*new_node;
    new_node=(struct Node*)malloc(sizeof(struct Node));
    if(new_node==NULL)
    {
        return 0;
    }
    new_node->info=p;
    new_node->next=NULL;
}

void insert(int n)
{
    struct Node*new_node,*temp;
    int i,num;
    for(i=0;i<n;i++)
    {
        printf("Enter the number:");
        scanf("%d",&num);
        new_node=getNode(num);
        if(last==NULL)
        {
            last=new_node;
            last->next=new_node;
        }
        else
        {
            temp=last->next;
            last->next=new_node;
            new_node->next=temp;
        }
    }
}

void insert_front()
{
    struct Node*new_node,*temp_start;
    int n;
    printf("Enter the number to be inserted: ");
    scanf("%d",&n);
    new_node=getNode(n);
    if(last==NULL)
    {
        last=new_node;
        last=last->next;
    }
    else
    {
        temp_start=last->next;
        last->next=new_node;
        new_node->next=temp_start;
    }
}

void insert_end()
{
    struct Node*new_node,*temp_start;
    int n;
    printf("Enter the number to be inserted: ");
    scanf("%d",&n);
    new_node=getNode(n);
    if(last==NULL)
    {
        last=new_node;
        last=last->next;
    }
    else
    {
        temp_start=last->next;
        last->next=new_node;
        new_node->next=temp_start;
        last=last->next;
    }
}

void delete_front()
{
    struct Node*temp;
    temp=last->next;
    last->next=temp->next;
    free(temp);
}

void delete_end()
{
    struct Node*temp;
    temp=last;
    int count=0;
    while(temp->next!=last)
    {
        count++;
        temp=temp->next;
    }
    last=temp;
    temp=temp->next;
    last->next=temp->next;
    free(temp);
}

void traverse()
{
    struct Node*temp=last->next;
    while(temp!=last)
    {
        printf("%d->",temp->info);
        temp=temp->next;
    }
    printf("%d",temp->info);
}

void main(){
    struct Node*new_node;
    int n,choice;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    insert(n);
    printf("Enter the required choice:\n1.Insert at front\n2.Insert at end");
    printf("\n3.Delete at front\n4.Delete at last\n");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
        insert_front();
        traverse();
        break;
        case 2:
        insert_end();
        traverse();
        break;
        case 3:
        delete_front();
        traverse();
        break;
        case 4:
        delete_end();
        traverse();
        break;
        default:
        printf("Invalid input");
    }
}