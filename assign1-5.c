#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
void addfirst(void);
void addlast(int,int);
int len(void);
void delfirst();
void dellast(int);
void reverse(void);
void checkempty(void);
void returnfirst(void);
void returnlast(void);

struct node
{
    int data;
    struct node *link;
};
struct node *root=NULL;
struct node *t;
struct node *last;
int main()
{
    int q1,q2,i,j,ch,ele,len;
    char a[5],st[5];
    char c;
    int number=0,digit;
    scanf("%d",&q1);
    while(q1--)
    {
        scanf("%d",&q2);
        while(q2--)
        {
            scanf("%s",a);
            if(strcmp(a,"I")==0)
    	{
        	ch=1;
    	}
    	if(strcmp(a,"AF")==0)
    	{
        	ch=2;
    	}
    	if(strcmp(a,"AL")==0)
    	{
        	ch=3;
    	}
    	if(strcmp(a,"RF")==0)
    	{
        	ch=4;
    	}
    	if(strcmp(a,"RL")==0)
    	{
        	ch=5;
    	}
    	if(strcmp(a,"L")==0)
    	{
        	ch=6;
    	}
    	if(strcmp(a,"F")==0)
    	{
        	ch=7;
    	}
    	if(strcmp(a,"REV")==0)
    	{
        	ch=8;
    	}
        switch (ch)
        {
        case 1:
                checkempty();
                break;
        case 2:
                addfirst();
                break;
        case 3:
                len=length();
                scanf("%d",&ele);
                addlast(ele,len);
                break;
        case 4:
                delfirst();
                break;
        case 5: len=length();
                dellast(len);
                break;
        case 8:
                reverse();
                break;
        case 6:
                returnlast();
                break;
        case 7: returnfirst();
                break;
        }
        }
    }
}
void checkempty()
{
    if(root==NULL)
        printf("true\n");
    else
        printf("false\n");
}
void addfirst()
{
    t=(struct node*)malloc(sizeof(struct node));
    scanf("%d",&t->data);
    t->link=NULL;
    if(root==NULL)
        root=t;
    else
    {
        last->link=t;
    }
    last=t;
    display();

}
int length()
{
    int count=0;
    t=root;
    while(t!=NULL)
    {
     count++;
     t=t->link;
    }
    return count;
}
void addlast(int ele,int len)
{   int i;
    struct node *pptr;
    t=(struct node *)malloc(sizeof(struct node));
    t->data=ele;
    t->link=NULL;
    if(root==NULL)
    {
        root=t;
        last=root;
        last->link=NULL;
    }
    else
    {
        last->link=t;
        last=t;
    }
    display();
}
void delfirst()
{
    struct node *pptr;
    t=root;
    root=root->link;
    free(t);
    display();
}
void dellast(int len)
{   int i;
    if(root==NULL)
    {
        printf("ListEmptyException\n");
    }
    else if(root==last)
    {
        root=NULL;
        last=NULL;
        display();
    }
    else
   {
        struct node *pptr;
    t=root;
    for(i=1;i<len&&t->link!=NULL;i++)
    {
        pptr=t;
        t=t->link;
    }
    pptr->link=t->link;
    free(t);
    display();
   }
}
void reverse()
{
    struct node *current,*prev=NULL;
    current=root;
    while(current!=NULL)
    {
       prev=root;
       current=root->link;
       root=root->link;
       prev->link=NULL;
       while(root!=NULL)
       {
           root=root->link;
           current->link=prev;
           prev=current;
           current=root;
       }
       root=prev;
    }
    display();
}

void display()
{
    t=root;
    {
        while(t!=NULL)
        {
            printf("%d->",t->data);
            t=t->link;
        }
    }
    printf("null\n");
}
void returnlast()
{
    printf("%d\n",last->data);
}
void returnfirst()
{
    printf("%d\n",root->data);
}

