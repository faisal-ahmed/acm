#include <stdio.h>

int bigmod (int b, int p, int m)
{
	if (p==0)
		return 1;
	else if (p%2==0)
	{
		int x = bigmod(b, p/2, m);
		return (x*x)%m;
	}
	else
		return ((b%m)*(bigmod(b, p-1, m)))%m;
}

int main()
{
	int b, p, m;

	while (scanf ("%d%d%d",&b,&p,&m)==3)
		printf ("%d\n",bigmod(b,p,m));

	return 0;
}