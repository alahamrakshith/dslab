#include <stdio.h>
#include <stdlib.h>
int main()
{
    int r,c,i,j,q,m1;
    printf("Enter row and column size\n");
    scanf("%d%d",&r,&c);
    int **x;
    x=(int **)malloc(sizeof(int)*r);
    for(i=0;i<r;i++)
    {
        *(x+i)=(int*)malloc(sizeof(int)*c);
        for(j=0;j<c;j++)
            {scanf("%d",&*(*(x+i)+j));}
    }
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            printf("%d ",*(*(x+i)+j));
        }
    }
    return 0;
}
