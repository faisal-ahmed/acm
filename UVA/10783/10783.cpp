#include  <stdio.h>

int main ()
{
	int a, b, res, kase;
	scanf ("%d",&kase);

	for (int j=1; j<=kase; j++)
	{
		res = 0;
		scanf ("%d%d",&a,&b);
		int i;
		if (a%2==0)
		{
			for (i=a+1; i<=b; i+=2)
				res += i;
		}
		else
		{
			for (i=a; i<=b; i+=2)
				res += i;
		}
		printf ("Case %d: %d\n", j, res);
	}

	return 0;
}