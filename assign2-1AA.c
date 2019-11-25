#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *ptr;
};

struct node *root=NULL,*root1=NULL,*last=NULL;

void insert(int ele)
{
    struct node *t;
    t=(struct node *)malloc(sizeof(struct node));
    t->data=ele;
    t->ptr=NULL;
    if(root==NULL)
        root=t;
    else
        last->ptr=t;
    last=t;
}

void display()
{
    struct node *t;
    for(t=root;t!=NULL;t=t->ptr)
    {
        printf("%d->",t->data);
    }
}

void display1()
{
    struct node *t;
    for(t=root1;t!=NULL;t=t->ptr)
    {
        printf("%d->",t->data);
    }
}

int main()
{   struct node *t;
    int i,size=0,pos,q;
    char a[100],temp,temp1,q1;
    while(1)
    {
        scanf(" %c->",&q1);
        if(q1=='N')
            goto finish;
        q=q1-'0';
        insert(q);
        size++;
    }
    finish:
    if(size>2)
    {
        if(size%2==1)
        {
            pos=((size)/2)+1;
        }
        else
            pos=size/2;
        t=root;
        for(i=1;i<pos;i++)
        {
           t=t->ptr;
        }
        root1=t->ptr;
        t->ptr=NULL;
    }
    display();
    printf("->NULL");
    printf("\n");
    display1();
    printf("->NULL");
    return 1;
}
