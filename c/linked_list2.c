#include <stdio.h>
#include <stdlib.h>

struct Node{
    int info;
    struct Node*next;
};

struct Node*start=NULL;

struct Node*getNode(int p)
{
    struct Node*new_node;
    new_node=(struct Node*)malloc(sizeof(struct Node));
    if(new_node==NULL)
    {
        printf("No memory");
        return 0;
    }
    new_node->info=p;
    new_node->next=NULL;
    return new_node;
}

void insert(int num)
{
    struct Node*new_node,*temp;
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

void main()
{
    int num;
    printf("Enter the number of elements: ");
    scanf("%d",&num);
    insert(num);
    //PrintAlternateNode();
    Swap_Pair();
    traverse();
}