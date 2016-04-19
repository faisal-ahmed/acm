#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

#define UN(v) { SORT(v); v.erase(unique(v.begin(), v.end()),v.end()); }
#define SORT(c) sort( (c).begin(), (c).end());
#define FOR(i, a, b) for ( (i) = (a); (i) < (b); (i)++ )
#define FORu(i, a, b) for ( (i) = (a); (i) >= (b); (i)-- )
#define CL(a,b) memset(a, b, sizeof (a))
#define lld I64d

const int inf = (1<<30);
const double pi = 2.0*acos(0);

struct state
{
	int u, d;
	state(){}
	state(int a, int b) { u = a; d = b; }
	bool operator < (state X) const
	{
		if (d!=X.d) return X.d < d;
		return X.u < u;
	}
};

int dist[10010];

int main()
{
	int kase;
	scanf ("%d",&kase);

	while (kase--)
	{
		int nr_city, cityCounter = 1, i;
		vector<state> conn[10010];
		scanf ("%d",&nr_city);
		getchar();
		map<string,int> city_index;
		while (nr_city--)
		{
			string a;
			char input[15];
			scanf ("%s",input);
			a = input;
			city_index[a] = cityCounter;
			int p;
			scanf ("%d",&p);
			while (p--)
			{
				int r, t;
				scanf("%d%d",&r,&t);
				conn[cityCounter].push_back(state(r,t));
			}
			cityCounter++;
		}
		int query;
		scanf("%d",&query);
		getchar();
		char one[15], two[15];
		while (query--)
		{
			scanf ("%s%s",one,two);
			string fr, to;
			fr = one; to = two;
			int s = city_index[fr], dest = city_index[to];
			FOR(i,0,10010) dist[i] = inf;
			priority_queue<state> pq;
			dist[s] = 0;
			pq.push(state(s,0));
			while (!pq.empty())
			{
				state cur = pq.top();
				if (cur.u == dest) break;
				pq.pop();
				if (cur.d > dist[cur.u]) continue;
				FOR(i,0,conn[cur.u].size())
				{
					int next = conn[cur.u][i].u, edge_cost = conn[cur.u][i].d;
					if (cur.d + edge_cost < dist[next])
					{
						dist[next] = cur.d + edge_cost;
						pq.push(state(next,dist[next]));
					}
				}
			}
			printf ("%d\n",dist[dest]);
		}
	}

	return 0;
}