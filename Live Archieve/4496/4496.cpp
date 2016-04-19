#include <stdio.h>
#define FOR(i,a,b) for (i=a; i<b; i++)
int main()
{
	int a, b, kase = 0;

	while (scanf ("%d%d",&a,&b)==2 && (a||b))
	{
		int min = 100, i, c;
		FOR(i,0,a) { scanf("%d",&c); if (c<min) min = c; }
		FOR(i,0,b) scanf("%d",&c);
		if (a>b) printf ("Case %d: %d %d\n",++kase,a-b,min);
		else printf ("Case %d: 0\n",++kase);
	}

	return 0;
}