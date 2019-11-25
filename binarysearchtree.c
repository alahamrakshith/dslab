#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *rc,*lc;
};
struct node *root=NULL;

struct node* bstinsert(struct node *root1,int ele)
{
    struct node *t;
    if(root1==NULL)
    {
        t=(struct node *)malloc(sizeof(struct node));
        t->data=ele;
        t->rc=t->lc=NULL;
        return t;
    }
    else if(ele>root1->data)
    {
        root1->rc=bstinsert(root1->rc,ele);
    }
    else if(ele<root1->data)
    {
        root1->lc=bstinsert(root1->lc,ele);
    }
    return root1;
};

struct node* minvalue(struct node *k)
{
 while(k->lc!=NULL)
 {
     k=k->lc;
 }
 return k;
}

struct node* bstdelete(struct node *root1,int ele)
{
    if(root1==NULL)
    {
        printf("Not found\n");
        return root1;
    }
    else if(ele>(root1->data))
    {
        root1->rc=bstdelete(root1->rc,ele);
    }
    else if(ele<(root1->data))
    {
        root1->lc=bstdelete(root1->lc,ele);
    }
    else
    {
        struct node *t1;
        if(root1->rc==NULL)
        {
            t1=root1->lc;
            free(root1);
            return t1;
        }
        if(root1->lc==NULL)
        {
            t1=root1->rc;
            free(root1);
            return t1;
        }
        t1=minvalue(root1->rc);
        root1->data=t1->data;
        root1->rc=bstdelete(root1->rc,t1->data);
        return root1;
    }
}

int maxdepth(struct node *t)
{
    if(t==NULL)
        return 0;
    else
    {
        int lh=maxdepth(t->lc);
        int rh=maxdepth(t->rc);
        if(lh>rh)
            return (lh+1);
        else
            return (rh+1);
    }
}

struct node* bstsearch(struct node *root1,int ele)
{
    if(root1==NULL)
    {
        printf("Not found\n");
        return root1;
    }
    else if(ele>root1->data)
    {
        bstsearch(root1->rc,ele);
    }
    else if(ele<root1->data)
    {
        bstsearch(root1->lc,ele);
    }
    else
        printf("found");
}

void display(struct node *t)
{
   if(t!=NULL)
   {
       printf("%d",t->data);
       display(t->lc);
       display(t->rc);
   }
}

int main()
{   int insdata,deldata,d,e,a;
    struct node *b,*c;
    while(1){
    printf("1.create\n2.delete\n3.search\n4.display\n5.height\n6.exit\n");
    int choice;
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:
            printf("Enter data to be inserted\n");
            scanf("%d",&insdata);
            root=bstinsert(root,insdata);
            break;
    case 2:
            printf("Enter data to be deleted\n");
            scanf("%d",&deldata);
            c=bstdelete(root,deldata);
            break;
    case 3: printf("Enter element to be searched\n");
            scanf("%d",&e);
            bstsearch(root,e);
            break;
    case 5:
            d=maxdepth(root);
            printf("%d\n",d);
            break;
    case 6: return 1;
            break;
    case 4: display(root);
            break;
    default:
            printf("Invalid input\n");
            break;
    }
    }
}
