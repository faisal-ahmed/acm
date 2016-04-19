#include <stdio.h>
#include <string.h>
#include <ctype.h>
bool visit[2000][110], line = 0;
char input[2000][110];

void floodfill(int i, int j)
{
	if (i<0 || j<0 || i>1900 || j>102 || visit[i][j] || input[i][j] != 'W')
		return;
	visit[i][j] = 1;
	int dr,dc;
	for (dr=-1; dr<=1; dr++)
		for (dc=-1; dc<=1; dc++)
			if (input[i+dr][j+dc] == 'W')
				floodfill(i+dr, j+dc);
}

int main()
{
//	freopen("out.txt","w",stdout);
	int kase, flag = 0;
	scanf ("%d",&kase);
	getchar();
	getchar();

	while (kase--)
	{
		memset(input,NULL,sizeof (input));
		int i=0, m, n,x,y, d=0;
		while(1)
		{
			int count = 0;
			gets(input[i]);
			if (input[i][0] == NULL)
			{
				if (kase > 0)
					puts("");
				break;
			}
			if (isdigit(input[i][0]))
			{
				x=y=d=0;
				while (isdigit(input[i][d]))
				{
					x*=10;
					x+=input[i][d] - '0';
					d++;
				}
				d++;
				while (isdigit(input[i][d]))
				{
					y*=10;
					y+=input[i][d] - '0';
					d++;
				}
				memset(visit,false,sizeof (visit));
				floodfill((x-1), (y-1));
				for (m=0; m<1900; m++)
					for (n=0; n<102; n++)
						count+=visit[m][n];
				printf ("%d\n",count);
			}
			i++;
		}
	}

	return 0;
}