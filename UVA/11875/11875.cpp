#include <stdio.h>

int main()
{
    int kase, tCase = 0; scanf ("%d",&kase);

    while (kase--)
    {
        int n, i, input[100];
        scanf ("%d",&n);
        for (i=0; i<n; i++)
        {
            scanf ("%d",&input[i]);
        }
        printf ("Case %d: %d\n",++tCase, input[n/2]);
    }

    return 0;
}
