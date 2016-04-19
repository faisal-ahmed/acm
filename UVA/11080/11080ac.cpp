#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int min(int a, int b)
{
	if (a>b)
		return b;
	return a;
}

int main()
{
	int kase;
	scanf ("%d",&kase);

	while (kase--)
	{
		vector<int>v[220];
		int node, edge, color = 3, btcolor[220], cCheck, flag = 0, one = 0, two = 0, ans = 0;
		memset(btcolor,0,sizeof (btcolor));
		scanf ("%d%d",&node ,&edge);
		for (int i=0; i<edge; i++)
		{
			int a, b;
			scanf ("%d%d",&a,&b);
			v[a].push_back(b);
			v[b].push_back(a);
		}
		for (int j=0; j<node; j++)
		{
			if (v[j].size()==0)
			{
				ans++;
				continue;
			}
			queue<int>Q;
			if (btcolor[j]==0)
			{
				one = two = 0;
				Q.push(j);
				btcolor[j] = 1;
				while (!Q.empty())
				{
					int u=Q.front();
					Q.pop();
					if (btcolor[u] == 1) one++;
					else two++;
					cCheck = color-btcolor[u];
					for (int m=0; m<v[u].size(); m++)
					{
						if (btcolor[v[u][m]] == btcolor[u])
						{
							flag = 1;
							break;
						}
						if (btcolor[v[u][m]]==0)
						{
							btcolor[v[u][m]] = cCheck;
							Q.push(v[u][m]);
						}
					}
					if (flag) break;
				}
				ans += min(one, two);
			}
			if (flag) break;
		}
		if (flag)
			puts("-1");
		else
			printf ("%d\n",ans);
	}
	
	return 0;
}