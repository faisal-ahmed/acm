#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;

#define FOR(i,a,b) for (i=a; i<b; i++)
#define setBit(i,j) (i|=(1<<j))
#define setTog(i,j) (i^=j)
#define CL(a,b) memset(a,b,sizeof(a))

int light, swi, ans[(1<<15)+2];
bool avail[(1<<15)+2];
int push[45];

int main()
{
	int kase, tCase = 0;
	scanf ("%d",&kase);

	while (kase--)
	{
		int i, j, q, distin = 0;
		long long value;
		CL(push,0);
		scanf ("%d%d", &light, &swi);
		FOR(i, 0, swi)
		{
			int n, temp;
			scanf ("%d",&n);
			FOR(j,0,n) { scanf ("%d",&temp); setBit(push[i],temp); }
		}
		scanf ("%d",&q);
		printf ("Case %d:\n",++tCase);

		FOR(i,0,(1<<15)+2) { ans[i] = (1<<30); avail[i] = 0; }
		queue<int>Q;
		Q.push(0);
		ans[0] = 0;
		avail[0] = 1;
		while (!Q.empty())
		{
			int operation = Q.front(), test;
			Q.pop();
			FOR(i,0,swi)
			{
				test = operation;
				setTog(test,push[i]);
				if (ans[operation]+1 < ans[test]) ans[test] = ans[operation] + 1;
				if (avail[test] == 0) { Q.push(test); avail[test] = 1; }
			}
		}

		while (q--)
		{
			int res = -1;
			distin = 0;
			scanf ("%lld",&value);
			FOR(i,0,light)
			{
				if (value%10) setBit(distin,i);
				value /= 10;
			}
			if (ans[distin] != (1<<30)) res = ans[distin];
			printf ("%d\n",res);
		}
		puts("");
	}

	return 0;
}