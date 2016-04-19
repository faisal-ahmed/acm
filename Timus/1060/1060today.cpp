//Special BFS
#include <stdio.h>
#include <queue>
using namespace std;
int target1 = (1<<16)-1, target2 = 0, value = 0, valueLF = 15, dis[(1<<16)+5], visit[(1<<16)+5];

int bfs(int n)
{
	if (n==target1 || n==target2)
		return 0;
	queue<int>Q;
	int u, v, i, temp = 0, lF = 15;
	Q.push(n);
	while (!Q.empty())
	{
		u=Q.front();
		Q.pop();
		if (u==target1 || u==target2)
			return dis[u];
		for (i=0; i<16; i++)
		{
			temp = i%4;
			v=u;
			v ^= (1<<(lF-i));
			if (temp - 1 >= 0)
				v ^= (1<<(lF-i+1));
			if (temp + 1 < 4)
				v ^= (1<<(lF-i-1));
			if (!(i>11))
				v ^= (1<<(lF-i-4));
			if (!(i<4))
				v ^= (1<<(lF-i+4));
			if (visit[v] == 0)
			{
				visit[v] = 1;
				dis[v] = dis[u] + 1;
				if (v==target1 || v==target2)
					return dis[v];
				Q.push(v);
			}
		}
	}
	return -1;
}

int main()
{
	char input[10];
	for (int i=0; i<4; i++)
	{
		gets(input);
		for (int j=0; j<4; j++)
		{
			if (input[j] == 'b')
				value |= (1<<valueLF);
			valueLF--;
		}
	}
	int res = bfs(value);
	if (res==-1)
		printf ("Impossible\n");
	else
		printf ("%d\n",res);

	return 0;
}