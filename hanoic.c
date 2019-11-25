# include<stdio.h>
int count =0;
void toh(int n , char s,char m,char d)
{

    if(n==1)
    {
        count++;
        printf("Move %d dish from %c to %c\n",n,s,d);
    }
    else
    {

        toh(n-1,s,d,m);
        count++;
        printf("Move %d dish from %c to %c\n",n,s,d);
        toh(n-1,m,s,d);
    }
}

void main()
{

    int n;
    printf("Enter number of disc: ");
    scanf("%d",&n);

    toh(n,'A','B','C');

    printf("minimum number of moves = %d",count);


}
