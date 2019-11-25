#include<stdio.h>
#include<stdlib.h>
inline int input()
{
    int n=0;
    int ch=getchar_unlocked();
    while(ch>='0'&&ch<='9')
        n=(n<<3)+(n<<1)+(ch-'0'),ch=getchar_unlocked();
    return n;
}
int main()
{
    int t,n,c,i;
    t=input();
    while(t--)
    {
        n=input();
        c=input();
        for(i=0;i<n;i++)
            c-=input();
        (c<0)?printf("No\n"):printf("Yes\n");
    }
    return 0;
}

