#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int findWordInAGrid(char grid[128][128],int m,int n,char word[32])
{   int z,i,j;
    int t1i,t1j,t2i,t2j;
    for(z=0;z<strlen(word);z++)
    {
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                if(word[z]==grid[i][j])
                {
                    t1i=i;
                    t1j=j;
                }
                if(word[z+1]!='\0')
                {
                    if(word[z+1]==grid[i][j])
                    {
                        t2i=i;
                        t2j=j;
                    }
                }
            }
        }
        if(word[z+1]!='\0')
            {if(abs(t2i-t1i)!=1&&abs(t2i-t1i)!=0&&abs(t2j-t1j)!=1&&abs(t2j-t1j)!=0)
                {return 0;}
             if(abs(t2i-t1i)>1||abs(t2j-t1j)>1)
                return 0;
            }
        }
    return 1;
}

int main()
{
    int i,j,x,choice;
    char word[32];
    char grid[128][128];
    int m,n;
    printf("Enter m&n\n");
    scanf("%d%d",&m,&n);
    if(m>100||m<0||n>100|n<0)
        return 0;
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf(" %c",&grid[i][j]);
        }
    }
    while(1)
    {   printf("1.search word\n2.exit\n");
        scanf("%d",&choice);
        switch(choice)
        { case 1:
                printf("Enter word\n");
                scanf("%s",word);
                x=findWordInAGrid(grid,m,n,word);
                if(x==0)
                    printf("\n%s : false\n",word);
                else if(x==1)
                    printf("\n%s : true\n",word);
                break;
          case 2: return 1;
                  break;
          default:
                    printf("Invalid input\n");
                    break;
        }
    }
}
