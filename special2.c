#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    char data;
    struct node *ptr;
    int count;
};

struct node *root=NULL;
struct node *last;

void insert(char ele)
{
    int flag=0;
    struct node *temp;
    struct node *t;
    t=(struct node *)malloc(sizeof(struct node));
    t->ptr=NULL;
    t->count=0;
    if(root==NULL)
       {
            root=t;
            t->data=ele;
            t->count++;
            last=t;
       }
    else
     {   temp=root;
         while(temp!=NULL)
        {
            if(temp->data==ele)
            {
                temp->count=temp->count+1;
                flag=1;
            }
            temp=temp->ptr;
        }
         if(flag!=1)
         {
             last->ptr=t;
             t->data=ele;
             t->count++;
             last=t;
         }
     }
}

void show()
{
    int c=0;
    struct node* temp;
    temp=root;
    if(temp==NULL)
    {
        printf("list empty\n");
    }
    else
    {
        while(temp!=NULL)
        {
            printf("%c  %d\n",temp->data,temp->count);
            temp=temp->ptr;
        }
    }
}

void arrange()
{
    int q;
    char c;
    struct node *temp,*pptr;
    for(pptr=root;pptr->ptr!=NULL;pptr=pptr->ptr)
    {
        for(temp=pptr->ptr;temp!=NULL;temp=temp->ptr)
        {
            if((pptr->count)<(temp->count))
            {
                c=pptr->data;
                pptr->data=temp->data;
                temp->data=c;
                q=pptr->count;
                pptr->count=temp->count;
                temp->count=q;
            }
        }
    }
}

void rem()
{   struct node  *t;
    t=root;
    t->count--;
}

int sum()
{   int total=0;
    struct node *t;
    for(t=root;t!=NULL;t=t->ptr)
    {
        total=total+(t->count*t->count);
    }
    return total;
}

void deleteList()
{
   struct node *current = root;
   struct node *next;
   while (current != NULL)
   {
       next = current->ptr;
       free(current);
       current = next;
   }
   root = NULL;
}

int main()
{
    int q,k,x,i;
    char str[50];
    scanf("%d\n",&q);
    if(q>100||q<1)
    {
        return 1;
    }
    while(q--)
    {
        scanf("%s",str);
        for(i=0;i<strlen(str);i++)
        {
            insert(str[i]);
        }
        scanf("%d",&k);
        while(k--)
        {
            arrange();
            rem();
        }
        x=sum();
        printf("%d\n",x);
        deleteList();

    }
    return 1;
}
