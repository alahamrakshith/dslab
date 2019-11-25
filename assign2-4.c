#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int size=10;

void pushq(int *queue,int *front,int *rear,int ele)
{
    if(*rear+1==size)
        printf("Overflow\n");
    else if(*rear==-1)
    {
        *rear=*front=0;
        *(queue+*rear)=ele;
    }
    else
        queue[++(*rear)]=ele;
}

int delq(int *queue,int *front,int *rear)
{   int ele;
    if(*front==-1)
        printf("Underflow\n");
    else if(*front==*rear)
    {
        ele=queue[*front];
        *front=*rear=-1;
        return ele;
    }
    else
        return queue[(*front)++];
}

void pushstack(int *stack,int *top,int ele)
{
    if(*top==size-1)
    {
        printf("Overflow\n");
    }
    else
    {
        *(stack+(++*top))=ele;
    }
}

int popstack(int *stack,int *top)
{
    if(*top==-1)
    {
        printf("Underflow\n");
    }
    else
    {
        return stack[(*(top))--];
    }
}

int main()
{   int queue1[10],q1front=-1,q1rear=-1;
    int stack1[10],stack2[10],top1=-1,top2=-1;

    int choice,ele,x,y,z,i,temp,temp2;
    printf("Enter stack\n");
    while(1)
    {
        printf("1.push\n2.delete\n3.exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: printf("Enter element\n");
                    scanf("%d",&ele);
                    pushstack(&stack1,&top1,ele);
                    break;

            case 2: x=popstack(&stack1,&top1);
                    printf("%d Has been popped\n",x);
                    break;
            case 3: goto finish;
                    break;
            default: printf("Invalid input\n");
                     break;
        }
    }
        finish:
            temp=top1;
            for(i=0;i<=temp;i++)
            {
                y=popstack(&stack1,&top1);
                pushstack(&stack2,&top2,y);
            }
            temp2=top2;
            for(i=0;i<=temp2;i++)
            {
                z=popstack(&stack2,&top2);
                pushq(&queue1,&q1front,&q1rear,z);
            }
            printf("The queue is\n");
            for(i=0;i<=temp;i++)
            {
                printf("%d\n",queue1[i]);
            }
    }
