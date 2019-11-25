#include <stdio.h>
#include <stdlib.h>
int inp(void);
inline int inp()
{
       int n=0;
    int ch=getchar_unlocked();
    while( ch >= '0' && ch <= '9' )
    n = (n<<3)+(n<<1) + ch-'0', ch=getchar_unlocked();
    return n;
}
int main()
{
    int q,i,n,c,sum=0,b;
    q=inp();
    while(q--)
    { sum=0;
    n=inp();
    c=inp();
    while(n--)
    {
        b=inp();
        sum=sum+(b+2);
    }
    if(sum<=c)
        printf("Yes\n");
    else
        printf("No\n");
    }
    return 0;
}


