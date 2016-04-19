#include <stdio.h>
#include <string.h>

#define FOR(i,a,b) for ( (i) = a; (i) < b; (i)++)
#define FORulta(i,a) for ( (i) = a; (i) >= 0; (i)--)
#define CL(a, b) memset(a,b,sizeof (a))

int value[120][120], best[120][120];

int max(int a, int b)
{
	if (a>b) return a;
	return b;
}

int f(int r, int c, int Hr, int Hc)
{
	if (r<0 || c<0 || r >= Hr || c >= Hc) return 1;
	if (best[r][c] != -1) return best[r][c];
	int ret = 1;

	if (r+1 < Hr && value[r][c] > value[r+1][c]) ret = max(ret, f(r+1,c,Hr,Hc)+1);
	if (c+1 < Hc && value[r][c] > value[r][c+1]) ret = max(ret, f(r,c+1,Hr,Hc)+1);
	if (r-1 >= 0 && value[r][c] > value[r-1][c]) ret = max(ret, f(r-1,c,Hr,Hc)+1);
	if (c-1 >= 0 && value[r][c] > value[r][c-1]) ret = max(ret, f(r,c-1,Hr,Hc)+1);

	return best[r][c] = ret;
}

int main()
{
	int kase;
	scanf ("%d",&kase);

	while (kase--)
	{
		char name[1000];
		int r, c, longest_run = 0, i, j;
		scanf ("%s",name);
		getchar();
		scanf ("%d%d",&r,&c);

		FOR(i,0,r) FOR(j,0,c) scanf ("%d",&value[i][j]);

		CL(best,-1);

		FOR(i,0,r) FOR(j,0,c) f(i, j, r, c);

		FOR(i,0,r) FOR(j,0,c) if (best[i][j] > longest_run) longest_run = best[i][j];

		printf ("%s: %d\n",name,longest_run);
	}

	return 0;
}