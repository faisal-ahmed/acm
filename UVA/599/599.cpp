#include <stdio.h>
#include <string.h>
int node_visit[60], tree, acorn, adj_mat[30][30], flag;

void visit(int in)
{
	node_visit[in] = 1;
	for (int i = 0; i<27; i++)
	{
		if (adj_mat[in][i] == 1 && node_visit[i] == 0)
		{
			visit(i);
			flag++;
		}
	}
}

int main()
{
	int t_case;
	scanf ("%d",&t_case);
	for (int i=1; i<=t_case; i++)
	{
		char node[60], edge[100];
		memset(adj_mat,0,sizeof (adj_mat));
		memset(node_visit,-1,sizeof (node_visit));
		tree = acorn = 0;
		while (scanf ("%s",edge)==1)
		{
			if (edge[0] == '*')
				break;
			else
			{
				adj_mat[edge[1] - 'A'][edge[3] - 'A'] = 1;
				adj_mat[edge[3] - 'A'][edge[1] - 'A'] = 1;
			}
		}
		scanf ("%s",node);
		int loop = strlen(node);
		for (int m=0; m<loop; m+=2)
			node_visit[node[m]-'A'] = 0;

		for (int j=0; j<27; j++)
		{
			flag = 0;
			if (node_visit[j] == 0)
			{
				visit(j);
				if (flag > 0)
					tree++;
				else
					acorn++;
			}
		}
		printf ("There are %d tree(s) and %d acorn(s).\n", tree, acorn);
	}
	
	return 0;
}