#include <stdio.h>
int main()
{   int n1,i,n2,big,small,x;
    printf("Enter the largest degree of the 1st equation\n");
    scanf("%d",&n1);
    n1++;
    int a[n1];
    for(i=0;i<n1;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Enter the largest degree of the 2nd equation\n");
    scanf("%d",&n2);
    n2++;
    int b[n2];
    for(i=0;i<n2;i++)
    {
        scanf("%d",&b[i]);
    }
    if(n2>n1)
        x=1;
    else
        x=0;
    if(x==1)
    {
        int c[n2];
        for(i=0;i<n1;i++)
        {
            c[i]=a[i]+b[i];
            printf("%d ",c[i]);
        }
        for(i=n1;i<n2;i++)
        {
            c[i]=b[i];
            printf("%d ",c[i]);
        }
    }
    else
    {
        int c[n1];
        for(i=0;i<n2;i++)
        {
            c[i]=a[i]+b[i];
            printf("%d ",c[i]);
        }
        for(i=n2;i<n1;i++)
        {
            c[i]=a[i];
            printf("%d",c[i]);
        }
    }
    return 0;
}
