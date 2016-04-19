#include <stdio.h>
#include <math.h>
int prime[1000500], prime_use[1000500], r=1;

int IsPrime(int a)
{
	int i, j=1;
	for (i=2; i*i<=a; i++)
		if (a%i==0)
			j=0;
	return j;
}

int main ()
{
	int input;
//	prime[0] = 1;
//	prime[1] = 0;
	int n = 1000500, a, f, j, k;
	for (a = 4; a < n; a+=2)
		prime[a] = 1;
	for (f = 3; f*f < n; f+=2)
	{
		if (prime[f]==0)
		{
			for (j = f*f; j < n; j+=f)
				prime[j] = 1;
		}
	}
	for (k=2; k < n; k++)
	{
		if (prime[k]==0)
		{
			prime_use[r] = k;
//			printf ("%d ",prime_use[r]);
			r++;
		}
	}
//	printf ("%d",prime_use[r-1]);

	while (scanf ("%d",&input)==1 && input)
	{
		int i, m, flag=1, prime_test = 0;
/*
		for (r=0; prime_use[r]<(int)(sqrt(input)); r++)
		{
			if (input%prime_use[r]==0)
			{
				printf ( "%d:\n%d+%d\n",input,prime_use[r],(input-prime_use[r]) );
				flag = 0;
				break;
			}
		}
		if (flag)
			printf ("%d:\nNO WAY!\n",input);*/

		for (i=input; 1; i--)                        // to find the location of that input to the prime numbers list.
		{
			if (prime_use[i]!=0)
			{
				if ((input-1)>prime_use[i])
					break;
				else if (input==prime_use[i])
				{
					i--;
					break;
				}
			}
		}
	
//		if (!prime_test)
//		{
			for (m=i; m>=(i-(int)(sqrt(i))); m--)
			{
				if (IsPrime(input-prime_use[m])==1)
				{
					printf ("%d:\n%d+%d\n",input,input-prime_use[m],prime_use[m]);
					flag = 0;
					break;
				}
		/*		for (n=0; n<=m; n++)
				{
					if (prime_use[m]+prime_use[n] == input)
					{
						flag = 1;
						break;
					}
					else if (prime_use[m]+prime_use[n] > input)
						break;
				}
				if (flag)
					break;*/
			}
			if (flag)
				printf ("%d:\nNO WAY!\n",input);
//		}
	}
	return 0;
}
