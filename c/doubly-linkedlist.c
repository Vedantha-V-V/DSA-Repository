#include <stdio.h>
#include <stdlib.h>

struct DNode{
    struct DNode*prev;
    int info;
    struct DNode*next;
};

struct DNode*start=NULL;

struct DNode*getNode(int p)
{
    struct DNode*new_node;
    new_node=(struct DNode*)malloc(sizeof(struct DNode));
    if(new_node==NULL)
    {
        return 0;
    }
    new_node->prev=NULL;
    new_node->next=NULL;
    new_node->info=p;
}

void insert(int n)
{
    struct DNode*new_node,*temp;
    int i,num;
    for(i=0;i<n;i++)
    {
        printf("Enter the number:");
        scanf("%d",&num);
        new_node=getNode(num);
        if(start==NULL)
        {
            start=new_node;
            temp=start;
        }
        else
        {
            temp->next=new_node;
            new_node->prev=temp;
            temp=temp->next;
        }
    }
}

void traverse()
{
    struct DNode*temp;
    temp=start;
    while(temp!=NULL)
    {
        printf("%d\t",temp->info);
        temp=temp->next;
    }
}

void insert_left()
{
    int key,n,count=0;
    printf("Enter the number to be inserted:");
    scanf("%d",&n);
    printf("Enter the key value:");
    scanf("%d",&key);
    struct DNode*temp=start;
    while(temp!=NULL && count==0)
    {
        if(temp->info==key && count==0)
        {
            struct DNode*new_node=getNode(n);
            struct DNode*back=temp->prev;
            count++;
            if(back==NULL)
            {
                new_node->next=start;
                start->prev=new_node;
                start=start->prev;
            }
            else
            {
                back->next=new_node;
                new_node->prev=back;
                new_node->next=temp;
                temp->prev=new_node;
            }
        }
        temp=temp->next;
    }
}

void delete()
{
    struct DNode*temp=start;
    int count=0,n;
    printf("Enter the value to be deleted:");
    scanf("%d",&n);
    while(temp!=NULL && count==0)
    {
        if(temp->info==n && count==0)
        {
            if(temp->next==NULL && temp->prev==NULL)
            {
                free(temp);
            }
            else
            {
                struct DNode*back=temp->prev;
                struct DNode*val=temp;
                temp=temp->next;
                back->next=temp;
                temp->prev=back;
                free(val);
                count++;
            }
        }
        temp=temp->next;
    }
}

void main()
{
    int num;
    printf("Enter the number of elements:");
    scanf("%d",&num);
    insert(num);
    //insert_left();
    delete();
    traverse();
}
