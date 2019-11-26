#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int top=-1;
char stack[50];
void push(char ele,int size)
{
    if(top==size-1)
        printf("Overflow\n");
    else
        stack[++top]=ele;
}

char pop()
{
    if(top==-1)
        printf("Underflow\n");
    else
        return stack[top--];
}

int prio(char x)
{
    if(x=='*'||x=='/')
        return 3;
    else if(x=='+'||x=='-')
        return 2;
    else
        return 1;
}

int main()
{   int j=0,i=0,size;
    char p[50],q[50];
    char sop,op2,op1;
    printf("Enter equation\n");
    scanf("%s",p);
    size=strlen(p);
    push('#',size);
    for(i=size-1;i>=0;i--)
    {
        if(p[i]=='+'||p[i]=='-'||p[i]=='/'||p[i]=='*')
        {
            sop=pop();
            while(prio(sop)>prio(p[i]))
            {
                q[j++]=sop;
                sop=pop();
            }
            push(sop,size);
            push(p[i],size);
        }
        else if(p[i]==')')
            push(')',size);
        else if(p[i]=='(')
        {
            sop=pop();
            while(sop!=')')
            {
                q[j++]=sop;
                sop=pop();
            }
        }
        else
            q[j++]=p[i];
    }
    sop=pop();
    while(sop!='#')
    {
        q[j++]=sop;
        sop=pop();
    }
    q[j]='\0';
    for(int k=size-1;k>=0;k--)
        printf("%c",q[k]);
}
