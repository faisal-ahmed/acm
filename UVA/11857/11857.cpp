#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

#define FOR(i,a,b) for (i=a; i<b; i++)
#define CL(a,b) memset(a,b,sizeof(a))

int node, edge, parent[1000002], rank[1000002];

struct info
{
	int fr, to, d;
	info(){}
	info(int a, int b, int c){ fr=a; to=b; d=c; }
	bool operator < (info X) const
	{
		return d<X.d;
	}
};
vector<info> input;

int find_set(int a)
{
	if (a==parent[a]) return a;
	return parent[a] = find_set(parent[a]);
}

void make_set(int a, int b)
{
	if (rank[a] == rank[b]) { parent[a] = b; rank[b]++; }
	else if (rank[a] < rank[b]) parent[a] = b;
	else parent[b] = a;
}

int main()
{
	while (scanf ("%d%d",&node,&edge)==2 && (node||edge))
	{
		int a, b, c, i, max = 0, flag = 0, temp1, temp2;
		input.clear();
		FOR(i,0,node) { parent[i] = i; rank[i] = 0; }
		FOR(i,0,edge) { scanf ("%d%d%d",&a,&b,&c); input.push_back(info(a,b,c)); }
		sort(input.begin(), input.end());
		FOR(i,0,input.size()) if ((temp1 = find_set(input[i].fr)) != (temp2 = find_set(input[i].to)))
		{
			make_set(temp1, temp2);
			if (max < input[i].d) max = input[i].d;
		}
		FOR(i,1,node) if (parent[i] != parent[i-1]) { puts("IMPOSSIBLE"); flag = 1; break; }
		if (!flag) printf ("%d\n",max);
	}

	return 0;
}