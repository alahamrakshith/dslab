#include <stdio.h>
#include <stdlib.h>
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
{
    int *a,*b,flag,big,small,i,j,count;
    int n1,n2;
    printf("Enter the number of elements of 1st array\n");
    n1=inp();
    a=(int *)malloc(sizeof(int*)*n1);
    printf("Input array elements : ");
    for(i=0;i<n1;i++)
    {
        *(a+i)=inp();
    }
    printf("Enter the number of elements of 2nd array\n");
    n2=inp();
    b=(int *)malloc(sizeof(int*)*n1);
    printf("Input array elements : ");
    for(i=0;i<n2;i++)
    {
        *(b+i)=inp();
    }
    if(n1>n2)
    {
        big=n1;
        small=n2;
        flag=0;
    }
    else if(n1<n2)
    {
        big=n2;
        small=n1;
        flag=1;
    }
    else
    {
        big=n1;
        small=n1;
        flag=3;
    }
    count=0;
    for(i=0;i<big;i++)
    {
        for(j=0;j<small;j++)
        {
            if(flag==0||flag==3)
            {
                if(*(b+j)==*(a+i))
                {
                    count++;
                }
            }
            else if(flag==1||flag==3)
            {
                if(*(a+j)==*(b+i))
                {
                    count++;
                }
            }
        }
    }
    if(count==small)
    {
        if(flag==1)
        {
            printf("1st array is the subset of 2nd\n");
        }
        else if(flag==0)
            printf("2nd array is the subset of 1st\n");
        else
            printf("Both are equal sets\n");
    }
    else
        printf("Not a subset\n");
    return 0;
}

