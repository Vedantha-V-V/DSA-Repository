#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node{
    char *name;
    int avail;
    int price;
    int rating;
    struct Node*next;
};

struct Node*start=NULL;

struct Node*getNode(char *hosp,int avail,int price,int rating)
{
    struct Node*new_node;
    new_node=(struct Node*)malloc(sizeof(struct Node));
    if(new_node==NULL)
    {
        return 0;
    }
    new_node->name=(char*)malloc(strlen(hosp)+1);
    strcpy(new_node->name,hosp);
    new_node->avail=avail;
    new_node->price=price;
    new_node->rating=rating;
    new_node->next=NULL;
    return new_node;
}

void insert(int num)
{
    struct Node*new_node,*temp;
    char name[20];
    int i,avail,price,rating;
    for(i=0;i<num;i++)
    {
        printf("Enter the hospital details:\n");
        printf("Name: ");
        scanf("%s",name);
        printf("Number of bed available: ");
        scanf("%d",&avail);
        printf("Price per bed: ");
        scanf("%d",&price);
        printf("Rating: ");
        scanf("%d",&rating);
        new_node=getNode(name,avail,price,rating);
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

void ratedBest(int num)
{
    struct Node*temp;
    temp=start;
    char *best;
    int rated=temp->rating;
    while(temp!=NULL)
    {
        if(temp->rating>rated)
        {
            best=temp->name;
        }
        temp=temp->next;
    }
    printf("\n%s",best);
}

void traverse(int num)
{
    struct Node*temp;
    temp=start;
    int i;
    for(i=0;i<num;i++)
    {
        while(temp!=NULL)
        {
            printf("%s\t",temp->name);
            printf("%d\t",temp->avail);
            printf("%d\t",temp->price);
            printf("%d\n",temp->rating);
            temp=temp->next;
        }
    }
}

void main()
{
    int num;
    printf("Enter the number of elements:\n");
    scanf("%d",&num);
    insert(num);
    traverse(num);
    ratedBest(num);
}