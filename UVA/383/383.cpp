#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;
int adj_mat[32][32], dis[32], color[32];

void bfs(int s, int M)
{
	memset(dis,0,sizeof (dis));
	memset(color,0,sizeof (color));
	queue<int>Q;
	Q.push(s);
	while (!Q.empty())
	{
		int u = Q.front();
		Q.pop();
		for (int v=0; v<M; v++)
		{
			if (adj_mat[u][v]==1 && color[v]==0)
			{
				Q.push(v);
				dis[v] = dis[u] + 1;
				color[v] = 1;
			}
		}
		color[u] = 2;
	}

}

int main()
{
//	freopen("out.txt","w",stdout);
	int d_set, dataset = 0;
	scanf ("%d",&d_set);
	printf ("SHIPPING ROUTES OUTPUT\n\n");

	while(d_set--)
	{
		printf ("DATA SET  %d\n\n",++dataset);
		memset(adj_mat,0,sizeof (adj_mat));
		int M, N, P, req;
		char node[32][2];
		scanf ("%d%d%d",&M,&N,&P);
		for (int i=0; i<M; i++)
		scanf ("%s",node[i]);
		for (int j=0; j<N; j++)
		{
			char edge[2][3];
			int first, second;
			scanf ("%s%s", edge[0], edge[1]);
			for (int k=0; k<M; k++)
			{
				if (strncmp(node[k],edge[0],2)==0)
					first = k;
				if (strncmp(node[k],edge[1],2)==0)
					second = k;
			}
			adj_mat[first][second] = 1;
			adj_mat[second][first] = 1;
		}
		for (int l=0; l<P; l++)
		{
			char req_edge[2][3];
			int f_res, s_res;
			scanf ("%d%s%s", &req, req_edge[0], req_edge[1]);
			if (N==0)
			{
				printf ("NO SHIPMENT POSSIBLE\n");
				continue;
			}
			for (int K=0; K<M; K++)
			{
				if (strncmp(node[K],req_edge[0],2)==0)
					f_res = K;
				if (strncmp(node[K],req_edge[1],2)==0)
					s_res = K;
			}
			bfs(f_res,M);
			if (dis[s_res] != 0)
				printf ("$%d\n",dis[s_res]*100*req);
			else
				printf ("NO SHIPMENT POSSIBLE\n");
		}
		puts("");
	}
	printf ("END OF OUTPUT\n");

	return 0;
}