#include <stdio.h>
int grid[65][65],qube[65];
int main()
{
	int input,i,x,y,j,k,flag;

	for (i=1;i<64;i++)
		qube[i] = i*i*i;
	for (x=1; x<64; x++)
		for (y=1; y<=x; y++)
			grid[x][y] = qube[x] - qube[y];

	while (scanf ("%d",&input)==1 && input)
	{
		flag = false;
		for (j=1;j<64;j++)
		{
			for (k=1;k<=j;k++)
			{
				if (grid[j][k] == input)
				{
					flag = true;
					break;
				}
			}
			if (flag)
				break;
		}
		if (j!=64)
			printf ("%d %d\n",j,k);
		else
			printf ("No solution\n");
	}

	return 0;
}