#include <stdio.h>

int main()
{
	int a, b;

	while (scanf ("%d%d",&a,&b)==2 && a>0 && b>0)
	{
		int res = 0;
		for (int i=1; i*i <= b; i++)
		{
			if (i*i>=a)
				res++;
		}
		printf ("%d\n", res);
	}

	return 0;
}