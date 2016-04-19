#include <stdio.h>

int main()
{
	int v, t;

	while (scanf ("%d%d",&v,&t)==2)
	{
		int res;
		res = 2*v*t;
		printf ("%d\n",res);
	}

	return 0;
}
