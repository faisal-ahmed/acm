#include <stdio.h>
#include <string.h>

int res[150][150];

int max(int a, int b)
{
	if (a>b) return a;
	return b;
}

int main()
{
	int tCase = 0;
	char input1[150], input2[150];

	while (gets(input1))
	{
		if (input1[0] == '#') break;
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
		printf ("Case #%d: you can visit at most %d cities.\n",++tCase,ans);
	}

	return 0;
}