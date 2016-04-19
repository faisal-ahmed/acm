#include <stdio.h>
bool prime[10008000];
int Isprime(long long a)
{
	long long i;
	if (a<2)return 0;
	if (a==2)return 1;
	if (a%2==0)return 0;
	for (i=3;i*i<=a;i+=2)
	{
		if (a%i==0)
			return 0;
	}
	return 1;
}

int main()
{
	long long input, i, count, value,j,k,m,test, hold;

	for (j=4; j<10008000; j+=2)
		prime[j] = true;
	for (k=3; k*k<10008000; k+=2)
	{
		if (prime[k] == false)
		{
			for (m=k*k; m<10008000; m+=k)
				prime[m] = true;
		}
	}

	while (scanf ("%lld",&input)==1 && input)
	{
		hold = 1;
		count = 0;
		if (input<0)
			input *= -1;
		test = input;
		for (i=2; i*i<=input; i++)
		{
			if (prime[i]==0 && test%i==0)
			{
				count++;
				value = i;
				while (test%i==0)
				{
					test/=i;
					hold *= i;
				}
				if (Isprime(input/hold))
				{
					count++;
					value = input/hold;
					break;
				}
			}
		}
		if (count>1)
			printf ("%lld\n",value);
		else
			printf ("-1\n");
	}

	return 0;
}