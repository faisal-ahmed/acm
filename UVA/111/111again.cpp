#include <stdio.h>
#include <map>
using namespace std;

int main()
{
	char input[50000];
	map<int,int> store;
	int n;
	scanf ("%d",&n);

	for (int i=1; i<=n; i++)
		scanf ("%d",&store[i]);
	while (gets(input))
	{
		int best[30];
		map<int,int> sorder;
		for (int mem=0; mem<=n; mem++)
			best[mem] = 1;
		int q=1, temp = 0, high = 1;
		for (int j=0; input[j] != NULL; j++)
		{
			if (input[j] == ' ' && j!=0)
			{
				if (input[j-1] != ' ')
				{
					sorder[temp] = q;
					temp = 0;
					q++;
				}
			}
			else if (input[j] != ' ')
			{
				temp *= 10;
				temp += (input[j] - '0');
			}
		}
		if (q==1)
			continue;
		if (temp != 0)
			sorder[temp] = q;

		for (int m=2; m<=n; m++)
		{
			for (int p=1; p<m; p++)
			{
				if ((store[sorder[m]] > store[sorder[p]]) && (best[m] < (best[p] + 1)) )
				{
					best[m] = best[p] + 1;
					if (best[m] > high)
						high = best[m];
				}
			}
		}
		printf ("%d\n",high);
	}

	return 0;
}