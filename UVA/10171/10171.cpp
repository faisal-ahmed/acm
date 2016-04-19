#include <stdio.h>
#include <string.h>
#include <string>
#include <ctype.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define FOR(i,a,b) for (i=a; i<b; i++)
#define CLR(a,b) memset(a,b,sizeof(a))
#define sz 30

const int inf = ((1<<30)-1);

int g1[sz][sz], g2[sz][sz], cost1[sz], cost2[sz];

struct state
{
    int u, d;
    state(){}
    state(int a, int b) { u=a; d=b; }
    bool operator < (state X) const
    {
        if (d!=X.d) return X.d<d;
        return X.u<u;
    }
};

void f(int s1, int s2)
{
    int i;
    FOR(i,0,30) { cost1[i] = cost2[i] = inf; }
    cost1[s1] = 0;
    cost2[s2] = 0;
    priority_queue<state> p1, p2;
    p1.push(state(s1,0));
    p2.push(state(s2,0));
    state curr;
    while (!p1.empty())
    {
        curr = p1.top();
        p1.pop();
        if (curr.d > cost1[curr.u]) continue;
        FOR(i,0,27)
        {
            if (g1[curr.u][i] != -1 && (curr.d + g1[curr.u][i]) < cost1[i])
            {
                cost1[i] = curr.d + g1[curr.u][i];
                p1.push(state(i,cost1[i]));
            }
        }
    }
    while (!p2.empty())
    {
        curr = p2.top();
        p2.pop();
        if (curr.d > cost2[curr.u]) continue;
        FOR(i,0,27)
        {
            if (g2[curr.u][i] != -1 && (curr.d + g2[curr.u][i]) < cost2[i])
            {
                cost2[i] = curr.d + g2[curr.u][i];
                p2.push(state(i,cost2[i]));
            }
        }
    }
}

int main()
{
    int node;

    while (scanf ("%d",&node)==1 && node)
    {
        getchar();
        CLR(g1,-1);
        CLR(g2,-1);
        int i;
        FOR(i,0,node)
        {
            char a, b, c, d;
            int value;
            scanf ("%c %c %c %c %d",&a,&b,&c,&d,&value);
            getchar();
            if (a=='Y')
            {
                if (b=='U') g1[c-'A'][d-'A'] = value;
                else { g1[c-'A'][d-'A'] = value; g1[d-'A'][c-'A'] = value; }
            }
            else
            {
                if (b=='U') g2[c-'A'][d-'A'] = value;
                else { g2[c-'A'][d-'A'] = value; g2[d-'A'][c-'A'] = value; }
            }
        }
        char sm, mg;
        int max = inf;
        scanf ("%c %c",&sm,&mg);
        int r = sm-'A', t = mg-'A';
        f(r,t);
        vector<char>place;
        char tt;
        FOR(i,0,27)
        {
            if ((cost1[i] != inf) && (cost2[i] != inf) && (cost1[i]+cost2[i]<max))
            {
                max = cost1[i]+cost2[i];
            }
        }
        FOR(i,0,27)
        {
            if (cost1[i]+cost2[i] == max)
            {
                tt = i+'A';
                place.push_back(tt);
            }
        }
        sort(place.begin(), place.end());
        if (max == inf) puts("You will never meet.");
        else
        {
            printf ("%d",max);
            FOR(i,0,place.size()) printf (" %c",place[i]);
            puts("");
        }
    }

    return 0;
}
