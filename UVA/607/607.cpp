#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

#define FOR(i,a,b) for (i=a; i<b; i++)
#define mx ((1<<31)-1)

int dt[1010][1010], n, L, C, T[1010];

int min(int a, int b)
{
    if (a>b) return b; return a;
}

int f(int d, int t)
{
    int ret = mx, i;
    if (t==0) return 0;
    if (d==1)
    {
        int limit = 0;
        FOR(i,1,t+1) limit += T[i];

        if (limit > L) ret = -2;
        else if (L-limit == 0) ret = 0;
        else if (L-limit <= 10) ret = -C;
        else ret = (L-limit-10)*(L-limit-10);
        return dt[d][t] = ret;
    }
    if (dt[d][t] != -1) return dt[d][t];

    int curLecTime = 0, wTime = 0, p;
    i=t;
    while (1)
    {
        curLecTime += T[i];
        if (curLecTime > L) break;
        wTime = L-curLecTime;
        if (wTime == 0) p = 0;
        else if (wTime <= 10) p = -C;
        else p = ((wTime-10)*(wTime-10));

        int temp = f(d-1,i-1);
        if (temp != -2) ret = min(ret,temp+p);

        i--;
        if (i==0) break;
    }
    if (ret == mx) return dt[d][t] = -2;
    return dt[d][t] = ret;
}

int main()
{
    int tCase = 0, i;
    while (scanf ("%d",&n)==1 && n)
    {
        memset(dt,-1,sizeof(dt));
        scanf ("%d%d",&L,&C);
        FOR(i,1,n+1) scanf ("%d",&T[i]);

        FOR(i,1,1001)
        {
            if (f(i,n) != -2) break;
        }
        if (tCase) puts("");
        printf ("Case %d:\n",++tCase);
        printf ("Minimum number of lectures: %d\n",i);
        printf ("Total dissatisfaction index: %d\n",dt[i][n]);
    }

    return 0;
}
