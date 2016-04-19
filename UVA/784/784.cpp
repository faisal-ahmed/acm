#include <stdio.h>
#include <string.h>
char grid[32][85];

void floodfill(int j, int k)
{
	int dc,dr;
	if (j<0 || k<0 || j>82 || k>82)
		return;
	grid[j][k] = '#';
	for (dr = -1; dr<=1; dr++)
		for(dc = -1; dc<=1; dc++)
			if (grid[j+dr][k+dc] == ' ')
				floodfill(j+dr,k+dc);
}

int main()
{
	int kase;
	scanf ("%d",&kase);
	getchar();

	while (kase--)
	{
		int i=0, j, m, n, k;
		memset(grid,NULL,sizeof(grid));
		while (1)
		{
			gets(grid[i]);
			if (grid[i][0] ==  '_')
				break;
			i++;
		}
		for (j=0; j<=i; j++)
			for (k=0; grid[j][k] != NULL; k++)
				if (grid[j][k] == '*')
					floodfill(j,k);
		for (m=0; m<=i; m++)
		{
			for (n=0; grid[m][n] != NULL; n++)
				printf ("%c",grid[m][n]);
			puts("");
		}
	}

	return 0;
}