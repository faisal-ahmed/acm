#include <stdio.h>
#include <string.h>
char grid[102][102];

void floodfill(int a, int b)
{
	if (a<0 || b<0 || a>101 || b>101)
		return;
	int dr, dc;
	grid[a][b] = '*';
	for (dr=-1; dr<=1; dr++)
		for (dc=-1; dc<=1; dc++)
			if (grid[a+dr][b+dc] == '@')
				floodfill((a+dr),(b+dc));
}

int main()
{
	int m,n,count,i,j,c,d;

	while (scanf ("%d%d",&m,&n)==2 && m)
	{
		getchar();
		memset(grid,NULL,sizeof(grid));
		count = 0;
		for (i=0; i<m; i++)
			gets(grid[i]);
		for (c=0; c<m; c++)
		{
			for (d=0; d<n; d++)
			{
				if (grid[c][d] == '@')
				{
					count++;
					floodfill(c,d);
				}
			}
		}
		printf ("%d\n",count);
	}

	return 0;
}