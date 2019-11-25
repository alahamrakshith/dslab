#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *lc,*rc;
};
struct node *root=NULL;

struct node *createbt()
{
    struct node *t;
    int ele;
    printf("Enter data, if no data then enter -1\n");
    scanf("%d",&ele);
    if(ele==-1)
    {
        return NULL;
    }
    t=(struct node *)malloc(sizeof(struct node));
    t->data=ele;
    printf("Enter the left child of %d\n",ele);
    t->lc=createbt();
    printf("Enter the right child of %d\n",ele);
    t->rc=createbt();
    return t;
};

void display(struct node *root)
{
    struct node *t;
    t=root;
    int ch;
    printf("Root is %d\n",t->data);
    while(1){
    printf("1.rightchild\n2.leftchild\n3.exit\n");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1: if(t->rc!=NULL)
                {t=t->rc;
                printf("%d\n",t->data);}
                else
                    printf("Doesn't exist\n");
                break;
        case 2: if(t->lc!=NULL)
                {
                    t=t->lc;
                    printf("%d\n",t->data);
                }
                else
                     printf("Doesn't exist\n");
                break;
        case 3:exit(1);
                break;
        default:printf("Wrong input\n");
                break;
    }
    }
}

void preorder(struct node *t)
{
 if(t!=NULL)
 {
     printf("%d\n",t->data);
     preorder(t->lc);
     preorder(t->rc);
 }
}
void inorder(struct node *t)
{
    if(t!=NULL)
    {
        inorder(t->lc);
        printf("%d\n",t->data);
        inorder(t->rc);
    }
}

void postorder(struct node *t)
{
    if(t!=NULL)
    {
        postorder(t->lc);
        postorder(t->rc);
        printf("%d\n",t->data);
    }
}

int maxdia(struct node *t)
{   int dia;
    if(t==NULL)
        return 1;
    else
    {
        int lh=maxdia(t->lc);
        int rh=maxdia(t->rc);
        if(lh>rh)
            return (lh+1);
        else
            return (rh+1);
    }
}

struct node* transverse(struct node *t)
{
    if(t->lc!=NULL)
        t=transverse(t->lc);
    else if(t->rc!=NULL)
        t=transverse(t->rc);
    if(t==root)
        return NULL;
    return t;
}


void main()
{
    struct node *x,*b;
    struct node *temp=root;
    int a=0,y,z,max=0;
    int ch;
    while(1)
    {
        printf("1.create\n2.display nomral\n3.display preorder\n4.display inorder\n5.display postorder\n6.exit\n7.depth\n");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
                x=createbt();
                a++;
                if(a==1)
                    b=x;
                break;
        case 2: display(x);
                break;
        case 3:
                preorder(b);
                break;
        case 4:
                inorder(b);
                break;
        case 5:
                postorder(b);
                break;
        case 6:
                exit(1);
                break;
        case 7: finish:
                y=maxdia(b->lc);
                z=maxdia(b->rc);
                if(y+z>max)
                    max=y+z;
                while(b->lc!=NULL)
                {
                    b=b->lc;
                    goto finish;
                }
                while(b->rc!=NULL)
                {
                    b=b->rc;
                    goto finish;
                }
                printf("Depth is %d\n",max-1);
                break;
        default:printf("Invalid\n");
                break;
        }
    }

}
