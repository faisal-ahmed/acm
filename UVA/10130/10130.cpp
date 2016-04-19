#include <stdio.h>
#include <string.h>

#define CL(a,b) memset(a, b, sizeof (a));
#define FOR(i, a, b) for ( (i) = a; (i) < b; i++)
#define FORulta(i, a) for ( (i) = a; (i) >= 0; i--)

int best[1000000];

struct object
{
	int p, w;
};

int main()
{
	int kase;
	scanf ("%d",&kase);

	while (kase--)
	{
		object list[1050];
		int nObject, nPerson, nPerCap[120], ans = 0, i, j;

		scanf ("%d",&nObject);
		FOR(i,0,nObject) scanf ("%d%d",&list[i].p, &list[i].w);
		scanf ("%d",&nPerson);
		FOR(i,0,nPerson) scanf ("%d",&nPerCap[i]);

		CL(best,0);
		FOR(i,0,nObject)
		{
			FORulta(j,35)
			{
				if (j+list[i].w > 35) continue;
				if (best[j] + list[i].p > best[j+list[i].w]) best[j+list[i].w] = best[j] + list[i].p;
			}
		}

		FOR(i,0,nPerson) ans += best[nPerCap[i]];
		printf ("%d\n",ans);
	}

	return 0;
}
