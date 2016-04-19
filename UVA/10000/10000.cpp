#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int dis[120];
void bfs(int s, vector<int> a[])
{
	queue<int>Q;
	Q.push(s);
	memset(dis,0,sizeof (dis));
	while (!Q.empty())
	{
		int u=Q.front();
		Q.pop();
		sort(a[u].begin(),a[u].end());
		for (int i=0; i<a[u].size(); i++)
		{
			if (dis[a[u][i]] < dis[u] + 1)
			{
				dis[a[u][i]] = dis[u] + 1;
				Q.push(a[u][i]);
			}
		}
	}
}

int main()
{
	int node, tCase = 0;

	while (scanf ("%d",&node)==1 && node)
	{
		vector<int>adj[120];
		int source, a, b;
		scanf ("%d",&source);
		while (scanf ("%d%d",&a, &b)==2 && (a||b))
			adj[a].push_back(b);
		bfs(source, adj);
		int max = 0, index = source;
		for (int i=0; i<=node; i++)
			if (dis[i] > max)
			{
				max = dis[i];
				index = i;
			}
		printf ("Case %d: The longest path from %d has length %d, finishing at %d.\n\n",++tCase,source,max,index);
	}

	return 0;
}