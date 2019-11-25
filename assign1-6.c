#include <stdio.h>
int inp(void);
inline int inp()
{
       int n=0;
    int ch=getchar();
    while( ch >= '0' && ch <= '9' )
    n = (n<<3)+(n<<1) + ch-'0', ch=getchar();
    return n;
}
int main()
{   int n,i,j;
    printf("Enter the size of the array\n");
    n=inp();
    int a[n];
    int b[n];
    printf("Enter elements of the array\n");
    for(i=0;i<n;i++)
    {
        a[i]=inp();
    }
    for(i=0;i<n;i++)
    {
        a[a[i]%n]=a[a[i]%n]+i*n;
    }
    for(i=0;i<n;i++)
    {
        a[i]=a[i]/n;
    }
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    return 0;
}

