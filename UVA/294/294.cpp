#include <stdio.h>
#include <string.h>
int prime[100000], primeNumber[100000];

int main()
{
	for (int i=4; i<100000; i+=2)
		prime[i] = 1;
	for (int j=3; j*j<100000; j+=2)
	{
		if (prime[j]==0)
		{
			for (int k=j*j; k<100000; k+=j)
				prime[k] = 1;
		}

	}
	int m=0;
	for (int l=2; l<100000; l++)
	{
		if (prime[l]==0)
		{
			primeNumber[m] = l;
			m++;
		}
	}
	int kase;
	scanf ("%d",&kase);

	while (kase--)
	{
		int l, h, count[100], highest = 0, total = 1, digit = 1;
		scanf ("%d%d",&l,&h);
		for (int f=l; f<=h; f++)
		{
			memset(count,0,sizeof (count));
			int temp = f;
			total = 1;
			int z=0;
			for (int r=0; primeNumber[r]*primeNumber[r]<=f; r++)
			{
				if (temp%primeNumber[r]==0)
				{
					count[z]++;
					temp/=primeNumber[r];
					while (temp%primeNumber[r]==0)
					{
						count[z]++;
						temp/=primeNumber[r];
					}
					z++;
				}
			}
			if (temp != 1)
				count[z]++;
			for (int e=0; e<100; e++)
			{
				if (count[e] != 0)
					total *= (count[e] + 1);
			}
			if (highest < total)
			{
				highest = total;
				digit = f;
			}
		}
		printf ("Between %d and %d, %d has a maximum of %d divisors.\n",l,h,digit,highest);
	}

	return 0;
}