#include <stdio.h>
#include <string.h>

int grid[30][30];
void floodfill(int r, int c)
{
	if (r<0 || c<0 || r>29 || c>29)
		return;
	grid[r][c] = 3;
	for (int dr = -1; dr <=1; dr++)
	{
		for (int dc = -1; dc <= 1; dc++)
		{
			if (grid[r+dr][c+dc] == 1)
				floodfill (r+dr,c+dc);
		}
	}
}

int main()
{
	int lim, kase = 0;
	while (scanf ("%d",&lim)==1)
	{
		memset (grid,-1,sizeof (grid));
		char input[30];
		for (int i=0; i<lim; i++)
		{
			scanf ("%s",input);
			for (int j=0; j<lim; j++)
			{
				grid[i][j] = input[j] - '0';
			}
		}
		int count = 0;
		for (int ro = 0; ro<lim; ro++)
		{
			for (int co = 0; co<lim; co++)
			{
				if (grid[ro][co] == 1)
				{
					floodfill(ro,co);
					count++;
				}
			}
		}
		printf ("Image number %d contains %d war eagles.\n",++kase,count);
	}
}