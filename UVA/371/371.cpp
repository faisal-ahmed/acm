#include <stdio.h>
//typedef long long int long long int;
long long int count = 0, flag = 0;

void det(long long int a)
{
	if (a==0)
		return;
	if (flag)
	{
		if(a==1)
			return;
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
	else
	{
		flag++;
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
	long long int x, y, h_count = 0, loop, whichgenerates = 0;

	while ( (scanf ("%lld%lld",&x,&y)) == 2)
	{
		if(x==0 && y==0)
			break;
		if ( x < y)
		{
			for (loop = x; loop <= y; loop++)
			{
				flag = 0;
				if (loop>=0)
					det(loop);
				else
					det(-loop);
				if (h_count < count)
				{
					whichgenerates=loop;
					h_count = count;
				}
				count = 0;
			}
		}
		else
		{
			for (loop = y; loop <= x; loop++)
			{
				flag = 0;
				if (loop>=0)
					det(loop);
				else
					det(-loop);
				if (h_count < count)
				{
					whichgenerates=loop;
					h_count = count;
				}
				count = 0;
			}
		}

		if (x<=y)
			printf ("Between %lld and %lld, %lld generates the longest sequence of %lld values.\n", x, y, whichgenerates, h_count);
		else
			printf ("Between %lld and %lld, %lld generates the longest sequence of %lld values.\n", y, x, whichgenerates, h_count);

		h_count = 0;
	}

	return 0;
}