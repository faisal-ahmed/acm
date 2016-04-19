#include <stdio.h>
#include <string.h>

int res[1040][1040];

int max(int a, int b)
{
	if (a>b) return a;
	return b;
}

int main()
{
	char input1[1200], input2[1200];

	while (gets(input1))
	{
		gets(input2);

		int ans = 0;
		memset(res, 0, sizeof (res));
		for (int i=0; input1[i] != NULL; i++)
		{
			for (int j=0; input2[j] != NULL; j++)
			{
				if (input1[i] == input2[j]) res[i+1][j+1] = res[i][j] + 1;
				else res[i+1][j+1] = max(res[i+1][j], res[i][j+1]);
				if (ans < res[i+1][j+1]) ans = res[i+1][j+1];
			}
		}
		printf ("%d\n",ans);
	}

	return 0;
}