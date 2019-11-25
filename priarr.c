#include <stdio.h>
int fr[3][2]={-1,-1,-1,-1,-1,-1};
int queue[3][10];
int size=10;

void insert(int pri,int ele)
{
    if((fr[pri][1]+1)%size==fr[pri][0])
        printf("Overflow\n");
    else if(fr[pri][0]==-1)
    {
        fr[pri][0]=fr[pri][1]=0;
        queue[pri][0]=ele;
    }
    else
    {
        fr[pri][1]=(fr[pri][1]+1)%size;
        queue[pri][fr[pri][1]]=ele;
    }
}

void del()
{
    int i;
    for(i=0;i<3;i++)
    {
        if(fr[i][0]!=-1)
        {
            printf("%d\n",queue[i][fr[i][0]]);
            if(fr[i][0]==fr[i][1])
             {
                 fr[i][0]=-1;
                 fr[i][1]=-1;
             }
             else
             {
                 fr[i][0]=(fr[i][0]+1)%size;
             }
             break;
        }
        if(i==4)
            printf("Underflow\n");
    }
}

void print()
{   int i,j;
    for(i=0;i<3;i++)
    {
        for(j=fr[i][0];j!=fr[i][1];j=(j+1)%size)
        {
            printf("%d",queue[i][j]);
        }
        printf("%d",queue[i][fr[i][1]]);
        printf("\n");
    }
}
void main()
{   int q,ele,prio;
    while(1)
    {
        printf("1.Insert\n2.Delete\n3.display\n4.exit\n");
        scanf("%d",&q);
        switch(q)
        {
            case 1: printf("Enter element\n");
                    scanf("%d",&ele);
                    printf("Enter priority\n");
                    scanf("%d",&prio);
                    insert(ele,prio);
                    break;
            case 2: del();
                    break;
            case 4: exit(1);
                    break;
            case 3: print();
                    break;
            default:
                    printf("Invalid entry\n");
                    break;

        }
    }
}


