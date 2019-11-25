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
    int *a,temp,q,i,j;
    int n;
    printf("Enter the number of elements\n");
    n=inp();
    a=(int *)malloc(sizeof(int*)*n);
    printf("Input array elements : ");
    for(i=0;i<n;i++)
    {
        *(a+i)=inp();
    }
    printf("Array in ascending order: ");
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(*(a+j)<*(a+i))
            {
                temp=*(a+j);
                *(a+j)=*(a+i);
                *(a+i)=temp;
            }
        }
        printf("%d ",*(a+i));
    }
    printf("\nArray in descending order: ");
    for(i=n-1;i>=0;i--)
    {
        printf("%d ",*(a+i));
    }
    return 1;
}

