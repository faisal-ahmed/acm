#include <stdio.h>
bool prime[10000000];
int main()
{
	for (int i=4; i<10000000; i+=2)
		prime[i] = 1;
	for (int j=3; j*j<10000000; j+=2)
	{
		if (prime[j] == 0)
		{
			for (int k=j*j; k<10000000; k+=j)
				prime[k] = 1;
		}
	}
	int kase;
	scanf ("%d",&kase);

	while (kase--)
	{
		long long int low, high, value, count = 0;
		scanf ("%lld%lld",&low,&high);
		for (long long int m=2; m*m<=high; m++)
		{
			if (prime[m]==0)
			{
				value = m;
				while ((value*=m)<=high)
				{
					if (value>=low)
						count++;
				}
			}
		}
		printf ("%lld\n",count);
	}

	return 0;
}