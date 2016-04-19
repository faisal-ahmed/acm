#include <stdio.h>
int value,res[5][5];

void place(int r, int c)
{
	res[r][c] = 1;
	for (int up = r-1; up>=0; up--)
	{
		if (res[up][c] == 2)
			break;
		else
			res[up][c] = 1;
	}
	for (int down = r+1; down<value; down++)
	{
		if (res[down][c] == 2)
			break;
		else
			res[down][c] = 1;
	}
	for (int le = c-1; le>=0; le--)
	{
		if (res[r][le] == 2)
			break;
		else
			res[r][le] = 1;
	}
	for (int rh = c+1; rh<value; rh++)
	{
		if (res[r][rh] == 2)
			break;
		else
			res[r][rh] = 1;
	}
}

int cal(int r, int c)
{
	int result = 1;
	for (int up = r-1; up>=0; up--)
	{
		if (res[up][c] == 2)
			break;
		else if (res[up][c] == 0)
			result++;
	}
	for (int down = r+1; down<value; down++)
	{
		if (res[down][c] == 2)
			break;
		else if (res[down][c] == 0)
			result++;
	}
	for (int le = c-1; le>=0; le--)
	{
		if (res[r][le] == 2)
			break;
		else if (res[r][le] == 0)
			result++;
	}
	for (int rh = c+1; rh<value; rh++)
	{
		if (res[r][rh] == 2)
			break;
		else if (res[r][rh] == 0)
			result++;
	}
	return result;
}

int main()
{
	char input[5];

	while (scanf("%d",&value)==1 && value)
	{
		getchar();
		int i, j, m, n, result = 0, row = 0, colm = 0, count = 0, min;
		for (i=0; i<value; i++)
		{
			gets(input);
			for (j=0; j<value; j++)
			{
				if (input[j] == '.')
					res[i][j] = 0;
				else
					res[i][j] = 2;
			}
		}
		for (m=0; m<value; m++)
		{
			result = min = 1000;
			for (n=0; n<value; n++)
			{
				if (res[m][n] == 0)
					result = cal(m,n);
				if (res[m][n] == 2 && min != 1000)
				{
					place(row, colm);
					count++;
					result = min = 1000;
				}
				if (result < min)
				{
					min = result;
					row = m; 
					colm = n;
				}
			}
			if (res[row][colm] == 0 && min != 1000)
			{
				place(row, colm);
				count++;
			}
		}
		printf ("%d\n",count);
	}

	return 0;
}