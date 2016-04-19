#include <stdio.h>
int count = 0;

void det(int a)
{
	if (a==1)
		count++;
	else
	{
		if (a%2==0)
		{
			count++;
			det(a/2);
		}
		else if (a%2==1)
		{
			count++;
			det(3*a+1);
		}
	}
}

int main ()
{
	int x, y, h_count = 0, loop;

	while ( (scanf ("%d%d",&x,&y)) == 2)
	{
		if ( x != 0 && y != 0)
		{
			if ( x < y)
			{
				for (loop = x; loop <= y; loop++)
				{
					det(loop);
					if (h_count < count)
						h_count = count;
					count = 0;
				}
			}
			else
			{
				for (loop = y; loop <= x; loop++)
				{
					det(loop);
					if (h_count < count)
						h_count = count;
					count = 0;
				}
			}
		}
		printf ("%d %d %d\n", x, y, h_count);
		h_count = 0;
	}

	return 0;
}