#include <stdio.h>
#include <string.h>

int res[1000010];

int NOD(int n)
{
    int ret = 1, i;
    for (i=2; i*i<=n; i++)
    {
        int count = 0;
        while (n%i==0)
        {
            count++;
            n/=i;
        }
        if (count > 0) ret *= (count+1);
    }
    if (n>1) ret *= 2;
    return ret;
}

int main()
{
    int i, temp = 1;

    while (temp < 1000010)
    {
        res[temp] = 1;
        temp = temp+NOD(temp);
    }
    for (i=1; i<1000010; i++) res[i] += res[i-1];

    int kase, tCase = 0; scanf ("%d",&kase);

    while (kase--)
    {
        int a, b;
        scanf ("%d%d",&a,&b);
        printf ("Case %d: %d\n",++tCase, res[b] - res[a-1]);
    }

    return 0;
}
