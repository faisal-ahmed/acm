#include <stdio.h>

int main()
{
	long long a, b, kase = 0;

	while (scanf ("%lld%lld",&a,&b)==2 && (a||b))
	{
		printf ("Case %lld: ",++kase);
		long long resB = 0, resA = 0, pow = 2;
		while ((pow>>1) <= b)
		{
			resB += (((b+1)/pow)*(pow>>1));
			if ( ((b+1)&(pow-1)) > (pow>>1)) resB += ((b+1)%pow - (pow>>1));
			if ((pow>>1) <= a)
			{
				resA += ((a/pow)*(pow>>1));
				if ( (a&(pow-1)) > (pow>>1)) resA += (a%pow - (pow>>1));
			}
			pow = (pow<<1);
		}
		printf ("%lld\n",resB-resA);
	}

	return 0;
}