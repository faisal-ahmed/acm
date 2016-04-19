#include <stdio.h>

int main()
{
	int num, kase = 0;

	while (scanf ("%d",&num)==1 && num >= 0)
	{
		int res = 1, count = 0;
		while (res < num)
		{
			res *=2;
			count++;
		}
		printf ("Case %d: %d\n", ++kase, count);
	}

	return 0;
}