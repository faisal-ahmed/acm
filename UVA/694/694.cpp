#include <stdio.h>

int main ()
{
	long long int a, limit, m, count=0;
	int i = 0;

	while (	scanf ("%lld%lld",&m,&limit)==2 && m>0 && limit>0)
	{
		a = m;
		i++;
		count = 0;
		for (;;)
		{
			if (a==1)
			{
				count++;
				break;
			}
			if (a>limit)
				break;
			else
			{
				if (a%2==0)
				{
					count++;
					a/=2;
				}
				else
				{
					count++;
					a=3*a+1;
				}
			}
		}
		printf ("Case %d: A = %lld, limit = %lld, number of terms = %lld\n",i, m, limit, count);
	}

	return 0;
}