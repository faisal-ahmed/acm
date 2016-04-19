#include <stdio.h>

int main()
{
    int n;

    while (scanf ("%d",&n)==1 && n)
    {
        int res = 0;
        while (n!=1)
        {
            int temp = n%3;
            res += (n/3);
            n = (n/3)+temp;
            if (n==2) n++;
        }
        printf ("%d\n",res);
    }

    return 0;
}
