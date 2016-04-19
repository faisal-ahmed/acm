#include <stdio.h>
#include <string.h>
#include <map>
#include <queue>
using namespace std;
int adjMat[100][100], dis[100], color[100], edge, visit, posNum;

void bfs(int s)
{
	memset(dis,0,sizeof (dis));
	memset(color,0,sizeof (color));
	queue<int>Q;
	Q.push(s);
	color[s] = 1;
	while (!Q.empty())
	{
		int u=Q.front();
		Q.pop();
		for (int i=0; i<=posNum; i++)
		{
			if (adjMat[u][i] == 1 && color[i] == 0)
			{
				visit++;
				Q.push(i);
				dis[i] = dis[u] + 1;
				color[i] = 1;
			}
		}
		color[u] = 2;
	}
}

int main()
{
	int kase = 0;
	while (scanf ("%d",&edge)==1 && edge)
	{
		posNum = 0;
		int nodeOne, nodeTwo;
		map<int, int>pos;
		memset(adjMat,0,sizeof (adjMat));
		for (int i=0; i<edge; i++)
		{
			scanf ("%d%d", &nodeOne, &nodeTwo);
			if (pos.find(nodeOne) == pos.end())
				pos[nodeOne] = ++posNum;
			if (pos.find(nodeTwo) == pos.end())
				pos[nodeTwo] = ++posNum;
			adjMat[pos[nodeOne]][pos[nodeTwo]] = adjMat[pos[nodeTwo]][pos[nodeOne]] = 1;
		}
		int nodeNum, ttl, res = 0;
		while (scanf ("%d%d", &nodeNum, &ttl)==2)
		{
			res = 0;
			visit = 1;
			if (nodeNum==0 && ttl==0)
				break;
			bfs(pos[nodeNum]);
			for (int j=0; j<=posNum; j++)
				if (dis[j] > ttl)
					res++;
			res += (posNum-visit);
			printf ("Case %d: %d nodes not reachable from node %d with TTL = %d.\n", ++kase, res, nodeNum, ttl);
		}
	}

	return 0;
}