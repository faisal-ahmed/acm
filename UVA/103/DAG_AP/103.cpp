#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

#define FOR(i,a,b) for (i=a; i<b; i++)
#define FORu(i,a,b) for (i=a; i>=b; i--)
#define FORsqtE(i,a,b) for (i=a; i*i <= b; i++)
#define CL(a,b) memset(a,b,sizeof(a))

int conn[32][32], hold[32][12], dimension, boxSec, dist[32], visited[32];
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

int dfs(int p)
{
	if (dist[p] != -1) return dist[p];
	visited[p] = 1;
	int i, value = 1, st = 0, in = 35;
	FOR(i,0,boxSec) if (conn[p][i] == 1) if(max(st,dfs(i))) { st = dist[i]; in = i; }
	value += st;
	if (in != 35) FOR(i,0,serial[in].size()) serial[p].push_back(serial[in][i]);
	return dist[p] = value;
}

int main()
{
	while (scanf ("%d%d",&boxSec, &dimension)==2)
	{
		int i, j, res = 0, flag = 0, test;
		CL(dist,-1);
		CL(visited,0);
		CL(conn,0);
		FOR(i,0,32) { serial[i].clear(); serial[i].push_back(i+1); }
		FOR(i,0,boxSec) FOR(j,0,dimension) scanf ("%d",&hold[i][j]);
		FOR(i,0,boxSec) sort(hold[i],hold[i]+dimension);
		FOR(i,0,boxSec) FOR(j,0,boxSec) if (small(i,j)) conn[j][i] = 1;
		test = dfs(0); test = 0;
		FOR(i,1,boxSec) if (!visited[i] && max(dist[test],dfs(i))) test = i;
		printf ("%d\n",dist[test]);
		FORu(i,serial[test].size()-1,0) if (!flag) { printf ("%d",serial[test][i]); flag = 1; } else printf (" %d",serial[test][i]);
		puts("");
	}

	return 0;
}