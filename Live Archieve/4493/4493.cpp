#include <stdio.h>
#include <math.h>
#include <queue>
using namespace std;

#define FOR(i,a,b) for (i=a; i<b; i++)

int main()
{
	int p, c, kase = 0;

	while (scanf ("%d%d",&p,&c)==2 && (p||c))
	{
		printf ("Case %d:\n",++kase);
		getchar();
		char input[100], prnt[100];
		queue<int> ans;
		int i, fil = 1, transfer, size, j, temp;
		FOR(i,1,c+1) { if (fil == p+1) break; ans.push(fil); fil++; }
		FOR(i,1,c+1)
		{
			gets(input);
			if (input[0] == 'N') { printf ("%d\n",ans.front()); temp = ans.front(); ans.pop(); ans.push(temp); }
			else
			{
				sprintf(prnt,"%s",input);
				sscanf(prnt,"%*c %d",&transfer);
				size = ans.size();
				ans.push(transfer);
				FOR(j,0,size)
				{
					temp = ans.front();
					ans.pop();
					if (temp != transfer) ans.push(temp);
				}
			}
		}
	}

	return 0;
}