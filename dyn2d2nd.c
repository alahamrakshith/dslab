#include <stdio.h>
int main()
{
    int *x,r,c,i,j;
    scanf("%d%d",&r,&c);
    x=(int*)malloc(sizeof(int)*r*c);
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            scanf("%d",&*(x+(i*c)+j));
        }
    }
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            printf("%d",*(x+(i*c)+j));
        }
    }
    return 0;
}
