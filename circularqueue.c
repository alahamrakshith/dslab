#include <stdio.h>
int queue[50];
int front=-1,rear=-1,size=50;

void insert(int ele)
{

    if((rear+1)%size==front)
        printf("Overflow\n");
    else if(rear==-1)
    {
        front=rear=0;
        queue[rear]=ele;
    }
    else
    {
        rear=(rear+1)%size;
        queue[rear]=ele;
    }
}

int del()
{
    if(front==-1)
        printf("Underflow\n");
    else if(front==rear)
    {
        printf("%d",queue[front]);
        front=rear=-1;
    }
    else
    {
        printf("%d",queue[front]);
        front=(front+1)%size;
    }
}

void print()
{   int i;
    if(front!=-1)
    {
        for(i=front;i!=rear;i=(i+1)%size)
            printf("%d",queue[i]);
        printf("%d",queue[i]);
    }
    else
        printf("No elements in array\n");
}

int main()
{   int ch,num;
    while(1)
    {
        printf("1.insert\n2.del\n3.print\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("Enter element\n");
                    scanf("%d",&num);
                    insert(num);
                    break;
            case 2: del();
                    break;
            case 3: print();
                    break;
        }
    }
}
