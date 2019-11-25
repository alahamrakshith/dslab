#include <stdio.h>
int n,count=0;
void find(int row,int col,int *a){
    a[n*row+col]=1;
    if(0<=row-1 && row-1<n  && !a[n*(row-1)+col] ){
        if(row-1==0 && col==0)
        count++;
        else
        find(row-1,col,a);
    }
     if(0<=row+1 && row+1<n && !a[n*(row+1)+col] ){
        if(row+1==0 && col==0)
        count++;
        else
        find(row+1,col,a);
    }
     if(0<=col-1 && col-1<n && !a[n*row+col-1] ){
        if(row==0 && col-1==0)
        count++;
        else
        find(row,col-1,a);
    }
    if(0<=col+1 && col+1<n && !a[row*n+col+1] ){
        if(row==0 && col+1==0)
        count++;
        else
        find(row,col+1,a);
    }
    a[n*row+col]=0;
}
int main(){
    scanf("%d",&n);
    int a[n][n];
    for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
    scanf("%d",&a[i][j]);
    if(!a[n-1][n-1])
    find(n-1,n-1,a);
    printf("%d",count);
}
