#include <stdio.h>
#include <stdlib.h>

void traverse();
void insert(int);
void insert_into_sorted(int);

struct Node {
    int info;
    struct Node* next;
};

struct Node* start=NULL;

struct Node*getNode(int n)
{
    struct Node*new_node;
    new_node=(struct Node*)malloc(sizeof(struct Node));
    if(new_node==NULL)
    {
        printf("No memory");
        return 0;
    }
    new_node->info=n;
    new_node->next=NULL;
    return new_node;
}

void traverse()
{
    struct Node*temp;
    temp=start;
    while(temp!=NULL)
    {
        printf("%d\t",temp->info);
        temp=temp->next;
    }
}

void insert(int num)
{
    struct Node*new_node;
    struct Node*temp;
    int i,n;
    for(i=0;i<num;i++)
    {
        printf("Enter the number: ");
        scanf("%d",&n);
        new_node=getNode(n);
        if(start==NULL)
        {
            start=new_node;
            temp=start;
        }
        else
        {
            temp->next=new_node;
            temp=temp->next;
        }
    }
}

void insert_into_sorted(int key)
{
    struct Node*new_node;
    new_node=getNode(key);
    if(start==NULL||start->info>key)
    {
        new_node->next=start;
        start=new_node;
    }
    else
    {
        struct Node *p,*q;
        p=start;
        q=NULL;
        while(p!=NULL && key > p->info)
        {
            q=p;
            p=p->next;
        }
        q->next=new_node;
        new_node->next=p;
    }
}

void bubble_sort()
{
    struct Node*ptr,*lptr;
    ptr=start;
    lptr=NULL;
    int temp;
    while (lptr!=start)
    {
        ptr=start;
        while(ptr->next!=lptr)
        {
            if(ptr->info > ptr->next->info)
            {
                temp=ptr->info;
                ptr->info=ptr->next->info;
                ptr->next->info=temp;
            }
            ptr=ptr->next;
        }
        lptr=ptr;
    } 
}

void fourth()
{
    int count=1;
    struct Node*temp;
    temp=start;
    while(temp!=NULL)
    {
        if(count==3)
        {
            printf("%d\n",temp->info);
            break;
        }
        count++;
        temp=temp->next;
    }
}

void main()
{
    int num,i,key;
    printf("Enter the number of elements:");
    scanf("%d",&num);
    insert(num);
    bubble_sort();
    //printf("Enter the number to be added: ");
    //scanf("%d",&key);
    //insert_into_sorted(key);
    fourth();
    traverse();
}

