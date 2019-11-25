#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int numrandom(int upper,int lower)
{
    int i,num;
    num =(rand()%(upper-lower+1))+lower;
    return num;
}

struct node
{
    int data;
    struct node *lc,*rc;
};
struct node *root1=NULL;
struct node *root2=NULL;
struct node *root3=NULL;
struct node *root4=NULL;

struct node* createbt(struct node *root,int ele)
{
    struct node *t;
    if(root1==NULL)
    {
        t=(struct node*)malloc(sizeof(struct node));
        t->data=ele;
        t->rc=t->lc=NULL;
        return t;
    }
    else if(ele>root1->data)
    {
        root1->rc=createbt(root1->rc,ele);
    }
    else if(ele<root1->data)
    {
        root1->lc=createbt(root1->lc,ele);
    }
    return root1;
}

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


int queue1[25],queue2[25],queue3[25],queue4[25],queuemain[100];
int front1=-1,front2=-1,front3=-1,front4=-1,frontmain=-1;
int rear1=-1,rear2=-1,rear3=-1,rear4=-1,rearmain=-1;
int size=25,sizemain=100;

void qinsert(int *queue,int size,int *front,int *rear,int ele)
{
    if(*(rear)+1==size)
        printf("Overflow\n");
    else if(*rear==-1)
    {
        *rear=*front=0;
        *(queue+*rear)=ele;
    }
    else
         *(queue+(++*rear))=ele;
}

int qdel(int *queue,int *front,int *rear)
{   int ele;
    if(*front==-1)
        printf("Underflow\n");
    else if(*front==*rear)
    {
        ele=*(queue+*front);
        *front=*rear=-1;
        return ele;
    }
    else
    {
        int x= *(queue+((*front)++));
        return x;
    }
}

void printqueue(int *queue,int *front,int *rear)
{   int i;
    for(i=0;i<=*rear;i++)
        printf("%d\n",*(queue+i));
}

int main()
{
    int lower,upper,count,x,choice,turn=0,temp,i;
    while(1){
    printf("1.Enter lower limit\n2.Enter upper limit\n3.Enter the number of numbers\n4.play the game\n5.exit\n");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1: scanf("%d",&lower);
                break;
        case 2: scanf("%d",&upper);
                break;
        case 3: scanf("%d",&count);
                break;
        case 5: exit(1);
                break;
        case 4: goto finish;
                break;
        default: printf("Invalid input\n");
                 break;
    }}
finish:
    srand(time(0));
    temp=count;
    while(temp--)
    {
        x=numrandom(upper,lower);
        qinsert(&queuemain,100,&frontmain,&rearmain,x);
    }
    printqueue(&queuemain,&frontmain,&rearmain);
    for(i=0;i<count;i++)
    {
        if(i%4==0)
        {
            temp=qdel(&queuemain,&frontmain,&rearmain);
            printf("%d\n",temp);
            createbt(temp);
        }
        /*else if(i%4==1)
        {
            temp=qdel(&queuemain,&frontmain,&rearmain);
            printf("%d\n",temp);
            createbt(&root2,temp);
        }
        else if(i%4==2)
        {
            temp=qdel(&queuemain,&frontmain,&rearmain);
            printf("%d\n",temp);
            createbt(&root3,temp);
        }
        else if(i%4==3)
        {
            temp=qdel(&queuemain,&frontmain,&rearmain);
            printf("%d\n",temp);
            createbt(&root4,temp);
        }*/
    }
    display(&root1);
}
