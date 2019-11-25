#include <stdio.h>
#include <string.h>
char stack[20];
int top=-1;
void push(int ele,int size)
{
    if(top==size-1)
    {   printf("%d",top);
        printf("Overflow\n");
    }
    else
    {
        stack[++top]=ele;
    }
}

int pop()
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
{
    int i=0,j=0;
    char q[20];
    int op2,op1;
    printf("Enter the expression\n");
    gets(q);
    int size=strlen(q);
    printf("%d",size);
    while(q[i]!='\0')
    {
        if(q[i]=='+'||q[i]=='-'||q[i]=='*'||q[i]=='/')
        {
            op2=pop();
            op1=pop();
            switch(q[i])
            {
                case '+': push(op1+op2,size);
                          break;
                case '-': push(op1-op2,size);
                          break;
                case '*': push(op1*op2,size);
                          break;
                case '/': push(op1/op2,size);
                          break;
            }
        }
        else
            push(q[i]-'0',size);
    }
    printf("\nResult %d",pop());
    return 0;
}
