#include <stdio.h>
#include <string.h>

char prime[20000000];

void primegen()
{
	int indexNo, bit, i, j;
	for (i=4; i<100010000; i+=2)
	{
		indexNo = (i-1)/8;
		bit = (i-1)%8;
		
		prime[indexNo] = (prime[indexNo] | (1<<bit));
	}
	for (i=3; i*i<100010000; i+=2)
	{
		indexNo = (i-1)/8;
		bit = (i-1)%8;
		
		if ( ((1<<bit) & prime[indexNo]) == 0)
		{
			for (j=i*i; j<100010000; j+=i)
			{
				indexNo = (j-1)/8;
				bit = (j-1)%8;
				prime[indexNo] = (prime[indexNo] | (1<<bit));
			}
		}
	}
}

int main()
{
	memset(prime, 0, sizeof (prime));

	primegen();

	int n, indexNo, bit, indexNo2, bit2;

	while (scanf ("%d",&n)==1)
	{
		if (n<5)
		{
			printf ("%d is not the sum of two primes!\n",n);
			continue;
		}
		if (n%2==1)
		{
			int check = (n-2);
			indexNo = (check-1)/8;
			bit = (check-1)%8;

			if ( ((1<<bit) & prime[indexNo]) == 0) printf ("%d is the sum of 2 and %d.\n",n, n-2);
			else printf ("%d is not the sum of two primes!\n",n);
			continue;
		}
		int loopStart = (n/2), i, flag = 1;
		if (loopStart % 2 == 0) loopStart++;
		else loopStart += 2;

		for (i=loopStart; i<n-1; i+=2)
		{
			indexNo = (i-1)/8;
			bit = (i-1)%8;
			indexNo2 = (n-i-1)/8;
			bit2 = (n-i-1)%8;
			
			if ( ((1<<bit) & prime[indexNo]) == 0 && ((1<<bit2) & prime[indexNo2]) == 0)
			{
				flag = 0;
				printf ("%d is the sum of %d and %d.\n",n, n-i, i);
				break;
			}
		}
		if (flag) printf ("%d is not the sum of two primes!\n",n);
	}

	return 0;
}