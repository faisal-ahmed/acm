//bipated check 10004
#include <stdio.h>
#include <string.h>
int adjMat[220][220], color[220], node, res;

void dfs(int n, int c)
{
	for (int j=0; j<node; j++)
	{
		if (adjMat[n][j] == 1 && (color[j] != c || color[j] == 0))
		{
			color[n] = c;
			adjMat[n][j] = adjMat[j][n] = 0;
			if (c==1)
				dfs(j,2);
			else
				dfs(j,1);
		}
		else if (adjMat[n][j] == 1 && color[j] == c)
		{
			res = 1;
			return;
		}
	}
}

int main()
{
	while (scanf ("%d",&node)==1 && node)
	{
		res = 0;
		memset(color,0,sizeof (color));
		int edge, a, b;
		scanf ("%d",&edge);
		for (int i=0; i<edge; i++)
		{
			scanf ("%d%d",&a,&b);
			adjMat[a][b] = adjMat[b][a] = 1;
		}
		dfs(0,1);
		if (res)
			printf ("NOT BICOLORABLE.\n");
		else
			printf ("BICOLORABLE.\n");
	}

	return 0;
}