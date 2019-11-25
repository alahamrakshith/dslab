#include <stdio.h>
#include <stdlib.h>
#define lim 150
int inp(void);
inline int inp()
{
       int n=0;
    int ch=getchar();
    while( ch >= '0' && ch <= '9' )
    n = (n<<3)+(n<<1) + ch-'0', ch=getchar();
    return n;
}
int main(void)
{
    int s[lim + 1];
    int i, m, t, x, y;
    t=inp();
    while (t--)
    {
        m=inp();
        x=inp();
        y=inp();
          for (i = 1; i <= lim; i++)
    	*(s+i) = 1;
          x *= y;
          for (m; m > 0; m--)
    	{
    	  y=inp();
    	  *(s+y) = 0;
    	  i = (y <= x) ? 1 : y - x;
    	  for (; i < y; i++)
    	    *(s+i) = 0;
    	  i = (y + x > lim) ? lim : y + x;
    	  for (; i > y; i--)
            *(s+i) = 0;
    	}

          for (y = 0, i = 1; i <= lim; i++)
    	if (s[i]!=0)
    	  y++;

          printf("%d\n",y);
        }

      return 0;
    }
