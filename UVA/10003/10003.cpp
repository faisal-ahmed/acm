#include <stdio.h>
#include <string.h>

#define FOR(i,a,b) for (i = a; i < b; i++)
#define CL(a,b) memset(a,b,sizeof(a))
#define FORu(i,a,b) for (i = a; i>=b; i--)
int dp[52][52], n, input[52], len;
int min(int a, int b) { if (a>b) return b; return a; }

int f(int a, int b)
{
	if (dp[a][b] != -1) return dp[a][b];
	if (b-a==1) return 0;
	int i, res = input[b]-input[a], test = (1<<30);
	FOR(i,a+1,b) test = min(test,f(a,i)+f(i,b));
	if (test != (1<<30)) res += test;
	return dp[a][b] = res;
}

int main()
{
//	freopen("out.txt","w",stdout);
	input[0] = 0;
	while (scanf ("%d",&len)==1 && len)
	{
		CL(dp,-1);
		int i, ans = (1<<30);
		scanf ("%d",&n);
		FOR(i,1,n+1) scanf ("%d",&input[i]);
		input[i] = len;
		printf ("The minimum cutting is %d.\n",f(0,n+1));
	}

	return 0;
}