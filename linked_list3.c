#include <stdio.h>
#include <stdlib.h>

struct Node{
    int info;
    struct Node*next;
};

struct Node*start=NULL;

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

void traverse(struct Node*temp)
{
    while(temp!=NULL)
    {
        printf("%d\t",temp->info);
        temp=temp->next;
    }
    printf("\n");
}

void main()
{
    int num;
    struct Node*posHead,*negHead;
    posHead=NULL;
    negHead=NULL;
    printf("Enter the number of elements: ");
    scanf("%d",&num);
    insert(num);
    split(start,&posHead,&negHead);
    printf("Original list:\n");
    traverse(start);
    printf("Positive list:\n");
    traverse(posHead);
    printf("Negative list:\n");
    traverse(negHead);
}