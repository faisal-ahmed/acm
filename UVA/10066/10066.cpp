#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;

int maxf(int a, int b)
{
	if (a>b) return a;
	return b;
}

int main()
{
	int a, b, tCase = 0;

	while (scanf ("%d%d",&a,&b)==2 && (a||b))
	{
		int i, test, j, res[105][105], max = 0;
		memset(res, 0, sizeof (res));
		vector<int> aL, bL;
		for (i=0; i<a; i++)
		{
			scanf ("%d",&test);
			aL.push_back(test);
		}
		for (i=0; i<b; i++)
		{
			scanf ("%d",&test);
			bL.push_back(test);
		}
		for (i=0; i<bL.size(); i++)
		{
			for (j=0; j<aL.size(); j++)
			{
				if (bL[i] == aL[j]) res[i+1][j+1] = res[i][j]+1;
				else res[i+1][j+1] = maxf(res[i+1][j], res[i][j+1]);
				if (res[i+1][j+1] > max) max = res[i+1][j+1];
			}
		}
		printf ("Twin Towers #%d\nNumber of Tiles : %d\n",++tCase,max);
		puts("");
	}

	return 0;
}