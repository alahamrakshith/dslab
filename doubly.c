#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node
{
    int roll;
    char address[10],branch[10],mobile[11],name[10],sec[2];
    struct node *pre;
    struct node *next;
};
struct node *last;
struct node* start=NULL;
struct node *t;
int len;
void insert(void);
void display(void);
void del(void);
void search(void);
void create(void);
void main()
{   int ch;
    while(1)
    {
        printf("Circular operations:\n");
        printf("1.create\n");
        printf("2.insertion\n");
        printf("3.deletion\n");
        printf("4.search\n");
        printf("6.display\n");
        printf("8.exit\n");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1: create();
                    break;
            case 2: insert();
                    break;
            case 3: del();
                    break;
            case 4: search();
                    break;
            case 6: display();
                    break;
            case 7: exit(1);
            default: printf("Invalid choice\n");
        }
    }
    return 0;
}

void create()
{   int n;
    printf("Enter no:of elements\n");
    scanf("%d",&n);
    while(n--)
    {
        t=(struct node *)malloc(sizeof(struct node));
        printf("Enter data\n");
        gets(t->name);
        gets(t->address);
        gets(t->mobile);
        gets(t->sec);
        scanf("%s",t->branch);
        scanf("%d",&t->roll);
        t->next=NULL;
        if(start==NULL)
        {
            start=t;
            t->pre=NULL;
        }
        else
        {
            last->next=t;
            t->pre=last;
        }
        last=t;
    }
}

void insert()
{   int ele,pos,i;
    printf("Enter element and position\n");
    scanf("%d%d",&ele,&pos);
    struct node *t1;
    t=(struct node *)malloc(sizeof(struct node));
    gets(t->name);
    gets(t->address);
    gets(t->mobile);
    scanf(" %c",&t->sec);
    gets(t->branch);
    scanf("%d",&t->roll);
    if(pos==1)
    {
        t->next=start;
        start->pre=t;
        t->pre=NULL;
    }
    else
    {
        t1=start;
        for(i=2;i<pos;i++)
        {
            t1=t1->next;
        }
        t->next=t1->next;
        t->pre=t1;
        if(t1->next!=NULL)
        {
            (t1->next)->pre=t;
        }
        t1->next=t;
    }
}
void del()
{   int pos,i;
    struct node *t1;
    if(start!=NULL)
    {
        printf("Enter position\n");
        if(pos==1)
        {
            t=start;
            start=start->next;
            free(t);
        }
        else
        {
            t=start;
            t1=start;
            for(i=1;i<pos;i++)
            {
                t1=t;
                t=t->next;
            }
            t1->next=t->next;
            if(t->next!=NULL)
            {
                (t->next)->pre=t1;
            }
            free(t);
        }
    }
}

void display()
{   int pos=0,q;
    if(start!=NULL)
    {   pos++;
        t=start;
        printf("%d\n",t->roll);
        printf("1.Print next\n");
        printf("2.print before\n");
        scanf("%d",&q);
        switch(q)
        {
            case 1:

        }
    }
}

void search()
{   int ele,count=0;
    printf("Enter roll no to be searched\n");
    scanf("%d",&ele);
    if(start!=NULL)
    {
        for(t=start;t->next!=start;t=t->next)
        {   count++;
            if(t->roll==ele)
            {
                printf("Student found at %d \n",count);
            }
        }
    }
    else
        printf("No elements in the array to search for\n");
}
