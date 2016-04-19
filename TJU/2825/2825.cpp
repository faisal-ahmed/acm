#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;
bool visit[100500];
int dis[100500], N, K, u, doub, minis, plas;

void bfs(int n)
{
	if (n>=K)
		printf ("%d\n",n-K);
	else
	{
		queue<int>Q;
		memset(dis,0,sizeof (dis));
		memset(visit,1,sizeof (visit));
		Q.push(n);
		while (!Q.empty())
		{
			u=Q.front();
			Q.pop();
			doub = u*2;
			minis = u-1;
			plas = u+1;
			if (doub != K)
			{
				if (visit[doub] && doub < K+2 && doub > 0)
				{
					visit[doub] = 0;
					Q.push(doub);
					dis[doub] = dis[u] + 1;
				}
			}
			else
			{
				printf ("%d\n",(dis[u]+1));
				return;
			}
			if (minis != K)
			{
				if (visit[minis] && minis < K && minis > 0)
				{
					visit[minis] = 0;
					Q.push(minis);
					dis[minis] = dis[u] + 1;
				}
			}
			else
			{
				printf ("%d\n",(dis[u]+1));
				return;
			}
			if (plas != K)
			{
				if (visit[plas] && plas < K)
				{
					visit[plas] = 0;
					Q.push(plas);
					dis[plas] = dis[u] + 1;
				}
			}
			else
			{
				printf ("%d\n",(dis[u]+1));
				return;
			}
		}
	}
}

int main()
{
	while (scanf ("%d%d",&N, &K)==2)
		bfs(N);
	return 0;
}