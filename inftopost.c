#include <stdio.h>
#include <string.h>
int top=-1;
char stack[20];

void push(char ele,int size)
{
    if(top==size-1)
    {
        printf("Overflow\n");
    }
    else
    {
        stack[++top]=ele;
    }
}

char pop()
{
    if(top==-1)
    {
        printf("Underflow\n");
    }
    else
    {
        return stack[top--];
    }

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
{   char q[20];
    char p[20];
    char sop;
    int i=0,j=0;
    printf("Enter expression\n");
    gets(p);
    int size=strlen(p);
    push('#',size);
    while(p[i]!='\0')
    {
        if(p[i]=='+'||p[i]=='-'||p[i]=='*'||p[i]=='/')
        {
          sop=pop();
          while(prio(sop)>=prio(p[i]))
          {
              q[j++]=sop;
              sop=pop();
          }
        push(sop,size);
        push(p[i],size);
        }
        else if(p[i]=='(')
            push('(',size);
        else if(p[i]==')')
        {
            sop=pop();
            while(sop!='(')
            {
                q[j++]=sop;
                sop=pop();
            }
        }
        else
            q[j++]=p[i];
        i++;
    }
    sop=pop();
    while(sop!='#')
    {
        q[j++]=sop;
        sop=pop();
    }
    q[j]='\0';
    for(int k=0;q[k]!='\0';k++)
    {
        printf("%c",q[k]);
    }
    return 0;
}


