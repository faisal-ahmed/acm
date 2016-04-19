//flood fill
#include <stdio.h>
#include <string.h>
char input[102][102];
int final[102][102];

void floodfill(int r, int c, int a, int b)
{
	if (r<0 || c<0 || r>a || c>b)
		return;
	for (int dr = -1; dr <=1; dr++)
	{
		for (int dc = -1; dc <= 1; dc++)
		{
			if (input[r+dr][c+dc] != '*')
				final[r+dr][c+dc]++; 
		}
	}
}

int main()
{
	int flag = 0, kase = 0, a, b;
	while (scanf ("%d%d",&a,&b)==2)
	{
		memset(final,0,sizeof(final));
		if (a==0 && b==0)
			break;
		for (int i=0; i<a; i++)
			scanf ("%s",input[i]);
		for (int j=0; j<a; j++)
		{
			for (int k=0; k<b; k++)
			{
				if (input[j][k] == '*')
					floodfill(j,k,a,b);
			}
		}
		if (flag)
			puts("");
		else
			flag++;
		printf ("Field #%d:\n",++kase);
		for (int p1=0; p1<a; p1++)
		{
			for (int p2=0; p2<b; p2++)
			{
				if (input[p1][p2] == '*')
					printf ("*");
				else
					printf ("%d",final[p1][p2]);
			}
			puts("");
		}
	}

	return 0;
}