#include <stdio.h>
#include <stdlib.h>
int n=0;

struct node
{
    char data;
    struct node *ptr;
};
struct node *root=NULL;
struct node *root1=NULL;
struct node *last,*last1;

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

void insert1(int ele)
{
    struct node *t;
    t=(struct node *)malloc(sizeof(struct node));
    t->data=ele;
    t->ptr=NULL;
    if(root1==NULL)
        root1=t;
    else
        last1->ptr=t;
    last1=t;
}

void display()
{
    struct node *t;
    for(t=root;t!=NULL;t=t->ptr)
    {
        printf("%c->",t->data);
    }
}

void display1()
{
    struct node *t;
    for(t=root1;t!=NULL;t=t->ptr)
    {
        printf("%c->",t->data);
    }
}

int main()
{   char a[100];
    int i;
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
            {
                if(n%2==0)
                {
                    insert(a[i]);
                    n++;
                }
                else
                {
                    insert1(a[i]);
                    n++;
                }
            }
        }
    }
    finish:
    display();
    printf("NULL");
    printf("\n");
    display1();
    printf("NULL");
    return 1;
}
