#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *lc,*rc;
    int ht;
};
struct node *root=NULL;
int height(struct node *t)
{
    if(t==NULL)
        return 0;
    else
    {
        int lh,rh;
        lh=height(t->lc);
        rh=height(t->rc);
        if(lh>rh)
            return lh+1;
        else
            return rh+1;
    }
}

int balfact(struct node *t)
{
    int lh,rh;
    if(t==NULL)
        return 0;
    if(t->lc==NULL)
        lh=0;
    else
        lh=t->lc->ht;
    if(t->rc==NULL)
        rh=0;
    else
        rh=t->rc->ht;
    return (lh-rh);
}
struct node* leftrotate(struct node *a)
{
    struct node *b=a->rc;
    a->rc=b->lc;
    b->lc=a;
    a->ht=height(a);
    b->ht=height(b);
}

struct node* rightrotate(struct node *a)
{
    struct node *b=a->lc;
    a->lc=b->rc;
    b->rc=a;
    a->ht=height(a);
    b->ht=height(b);
}
struct node* llrotation(struct node *t)
{
    t=rightrotate(t);
    return t;
}

struct node* rrrotation(struct node *t)
{
    t=leftrotate(t);
    return t;
}



struct node* rlrotation(struct node *t)
{
    t->rc=rightrotate(t->rc);
    t=leftrotate(t);
    return t;
}
struct node* lrrotation(struct node *t)
{
    t->lc=leftrotate(t->lc);
    t=rightrotate(t);
    return t;
}

struct node* insert(struct node *t,int ele)
{
    if(t==NULL)
    {
        t=(struct node *)malloc(sizeof(struct node));
        t->data=ele;
        t->lc=t->rc=NULL;
    }
    else if(ele>t->data)
    {
        t->rc=insert(t->rc,ele);
        if(balfact(t)==-2)
        {
            if(ele>t->rc->data)
                t=rrrotation(t);
            else
                t=rlrotation(t);
        }
        t->ht=height(t);
        return t;
    }
    else if(ele<t->data)
    {
        t->lc=insert(t->lc,ele);
        if(balfact(t)==2)
        {
            if(ele>t->lc->data)
                t=llrotation(t);
            else
                t=lrrotation(t);
        }
        t->ht=height(t);
        return t;
    }
}



void preorder(struct node *t)
{
    if(t==NULL)
        return 0;
    else
    {
        printf("%d",t->data);
        preorder(t->lc);
        preorder(t->rc);
    }
}

int main()
{   int num,ele,i;
    printf("Enter the number of elements you want to insert\n");
    scanf("%d",&num);
    for(i=1;i<=num;i++)
    {   printf("Enter the number %d \n ",i);
        scanf("%d",&ele);
        root=insert(root,ele);
    }
    preorder(root);
}
