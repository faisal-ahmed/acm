#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

#define FOR(i,a,b) for (i=a; i<b; i++)
#define FORu(i,a,b) for (i=a; i>=b; i--)
#define FORsqtE(i,a,b) for (i=a; i*i <= b; i++)
#define CL(a,b) memset(a,b,sizeof(a))

int dp[32], hold[32][12], dimension, boxSec;
vector<int> serial[32];

bool small(int a, int b)///return a < b
{
	int i;
	FOR(i,0,dimension) if (hold[a][i] >= hold[b][i]) return false;
	return true;
}

bool max(int a, int b)
{
	if (b>a) return true;
	return false;
}

int f(int boxNo)
{
	if (dp[boxNo] != -1) return dp[boxNo];
	int value = 1, i, change = 35;
	FOR(i,0,boxSec) if (small(i,boxNo))
	{
		if (max(value,1+f(i)))
		{
			value = dp[i]+1;
			change = i;
		}
	}
	if (change != 35) FOR(i,0,serial[change].size()) serial[boxNo].push_back(serial[change][i]);
	return dp[boxNo] = value;
}

int main()
{
	while (scanf ("%d%d",&boxSec, &dimension)==2)
	{
		int i, j, res = 0, flag = 0, test; ///dp[x] mane holo x tomo box sobar upore thakle maximum koto length er string....
		CL(dp,-1);
		FOR(i,0,32) { serial[i].clear(); serial[i].push_back(i+1); }
		FOR(i,0,boxSec) FOR(j,0,dimension) scanf ("%d",&hold[i][j]);
		FOR(i,0,boxSec) sort(hold[i],hold[i]+dimension);
		test = f(0);
		FOR(i,1,boxSec) if (max(dp[res],f(i))) res = i;
		printf ("%d\n",dp[res]);
		FORu(i,serial[res].size()-1,0) if (!flag) { printf ("%d",serial[res][i]); flag = 1; } else printf (" %d",serial[res][i]);
		puts("");
	}

	return 0;
}