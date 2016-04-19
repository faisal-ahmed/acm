#include <stdio.h>
int prime[1000005];

int main()
{
	int input, i, j, k, l, temp, value;

	prime[0] = 1;
	for (i=4; i<1000002; i+=2)
		prime[i] = 1;
	for (j=3; j*j < 1000002; j+=2)
	{
		if (prime[j]==0)
		{
			for (k=j*j; k<1000002; k+=j)
				prime[k] = 1;
		}
	}

	for (l=1; l<1000000; l++)
	{
		temp = 0;
		value = 0;
		if (prime[l]==0)
		{
			temp = l;
			value = temp%10;
			temp /= 10;
			while (temp!=0)
			{
				value = ((value * 10) + temp%10);
				temp /= 10;
			}
			if (value != l)
			{
				if (prime[value]==0)
				{
					prime[l]=2;
					prime[value] = 2;
				}
			}
		}
	}

	while (scanf ("%d",&input)==1)
	{
		if (prime[input]==2)
			printf ("%d is emirp.\n", input);
		else if (prime[input]==0)
			printf ("%d is prime.\n", input);
		else
			printf ("%d is not prime.\n", input);
	}

	return 0;
}