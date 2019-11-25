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
    int count=0;
    int i,size=0,pos,q,q1;
    char a[100];
   while(1)
    {
        scanf("%s",a);
        for(i=0;i<strlen(a);i++)
        {
            if(a[i]=='-'||a[i]=='>')
                continue;
            else if(a[i]=='N'&&a[i+1]=='U'&&a[i+2]=='L'||a[i+3]=='L')
                goto finish;
            else
            {   if(a[i+1]==' '||a[i+1]=='-')
                {
                    q=a[i]-'0';
                    insert(q);
                    size++;
                }
                else
                {   q1=i;
                    for(a[q1];a[q1]!='-'||a[q1]!=' ';a[q1]=a[q1+1])
                        count++;
                    sum=sum
                }
            }
        }
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
    else
    {   t=root;
        root1=t->ptr;
        t->ptr=NULL;
    }
    display();
    printf("NULL");
    printf("\n");
    display1();
     printf("NULL");
    return 1;
}
