#include<stdio.h>
#include<stdlib.h>

void read_array(int* arr, int n)
{
  for(int i = 0 ; i < n ; i++)
    scanf("%d",arr+i);
}

int arr_sum(int* arr, int n)
{
  int sum = 0;
  for(int i = 0 ; i < n ; i++)
    sum += *(arr+i);
  return sum;
}

int arr_min(int* arr, int n)
{
  int min = 10000;
  for(int i = 0 ; i < n ; i++)
  {
    if(*(arr+i) < min)
      min = *(arr+i);
  }
  return min;
}


int main()
{
  int T;
  scanf("%d",&T);

  while(T--)
  {
    int N;
    scanf("%d",&N);
    int* W = (int*)malloc(sizeof(int)*N);
    read_array(W,N);
    int result = arr_sum(W,N) - (N*arr_min(W,N));
    printf("%d\n",result);
  }
  return 0;
}
