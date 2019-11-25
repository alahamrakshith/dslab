
#include <stdio.h>
#include <stdlib.h>
int count=0;
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

struct node *root=NULL;
struct node *last;

struct node* insert(int ele)
{
    struct node *t;
    t=(struct node *)malloc(sizeof(struct node));
    t->data=ele;
    t->next=NULL;
    if(t==NULL)
        printf("Overflow\n");
    else
    {
        if(root==NULL)
        {
             root=t;
             t->prev=NULL;
        }
        else
        {
            last->next=t;
            t->prev=last;
        }
        last=t;
    }
    count++;
    return last;
}

struct node* checkdel()
{
    struct node *t;
    t=root;
    while(t->next!=NULL)
    {
        if(t->next->data>t->data)
        {
            if(t->prev==NULL)
            {
                root=t->next;
                t->next->prev=NULL;
            }
            else
            {
                t->prev->next=t->next;
                t->next->prev=t->prev;
            }
        }
        t=t->next;
    }
}

void display()
{
    struct node *t;
    t=root;
    for(t=root;t!=NULL;t=t->next)
    {
        printf("%d->",t->data);
    }
}
void main()
{   struct node *l;
    printf("Enter the linked list\n");
    int choice,ele;
    while(1)
    {
        printf("1.insert\n2.exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: printf("Enter the element\n");
                    scanf("%d",&ele);
                    insert(ele);
                    break;
            case 2: goto finish;
                    break;
            default: printf("Invalid input\n");
                    break;
        }
    }
    finish:
    checkdel();
    display();
    printf("NULL");
}
