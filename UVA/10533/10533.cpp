#include <stdio.h>

int prime[1000005], prime_digit[1000005];

int main()
{
	int hisab = 1;
	for (int i = 4; i<1000005; i+=2)
		prime[i]=1;
	for (int j=3; j*j<1000005; j+=2)
	{
		if (prime[j]==0)
		{
			for (int k=j*j; k<1000005; k+=j)
				prime[k] = 1;
		}
	}

	for (int l=2; l<1000005; l++)
	{
		if (prime[l]==0)
		{
			int temp = l, value = 0;
			while (temp!=0)
			{
				value += temp%10;
				temp /= 10;
			}
			if (prime[value]==0)
			{
				prime_digit[l] = hisab;
				hisab++;
			}
		}
	}
	int kase;
	scanf ("%d",&kase);

	while (kase--)
	{
		int a, b, result1 = 0, result2 = 0;
		scanf ("%d%d",&a,&b);
		for (int m=a-1; m>0; m--)
		{
			if (prime_digit[m]!=0)
			{
				result1 = prime_digit[m];
				break;
			}
		}
		for (int m2=b; m2>0; m2--)
		{
			if (prime_digit[m2]!=0)
			{
				result2 = prime_digit[m2];
				break;
			}
		}
		printf ("%d\n",result2-result1);
	}

	return  0;
}