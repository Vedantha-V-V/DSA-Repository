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

void PrintAlternateNode()
{
    struct Node*temp;
    temp=start;
    int count=1;
    while(temp!=NULL)
    {
        if(count%2!=0)
        {
            printf("%d\t",temp->info);
        }
        count++;
        temp=temp->next;
    }
}

void Swap_Pair()
{
    struct Node*ptr1,*ptr2;
    ptr1=start;
    int num;
    if(ptr1->next==NULL)
    {
        printf("\nNo swap required");
    }
    else
    {
        while (ptr1!=NULL && ptr1->next!=NULL)
        {
            ptr2=ptr1->next;
            num=ptr1->info;
            ptr1->info=ptr2->info;
            ptr2->info=num;
            ptr1=ptr2->next;
        } 
    }
}

void split(struct Node*temp,struct Node**posHead,struct Node**negHead)
{
    struct Node*posTail=NULL;
    struct Node*negTail=NULL;
    while(temp!=NULL)
    {
        if(temp->info>=0)
        {
            if(*posHead==NULL)
            {
                *posHead=getNode(temp->info);
                posTail=*posHead;
            }
            else
            {
                posTail->next=getNode(temp->info);
                posTail=posTail->next;
            }
        }
        else
        {
            if(*negHead==NULL)
            {
                *negHead=getNode(temp->info);
                negTail=*negHead;
            }
            else
            {
                negTail->next=getNode(temp->info);
                negTail=negTail->next;
            }
        }
        temp=temp->next;
    }
}


void main()
{
    int num,i,key;
    struct Node*posHead,*negHead;
    posHead=NULL;
    negHead=NULL;
    printf("Enter the number of elements:");
    scanf("%d",&num);
    insert(num);
    bubble_sort();
    //printf("Enter the number to be added: ");
    //scanf("%d",&key);
    //insert_into_sorted(key);
    fourth();
    traverse();
    //PrintAlternateNode();
    Swap_Pair();
    traverse();
    split(start,&posHead,&negHead);
    printf("Original list:\n");
    traverse(start);
    printf("Positive list:\n");
    traverse(posHead);
    printf("Negative list:\n");
    traverse(negHead);
}

