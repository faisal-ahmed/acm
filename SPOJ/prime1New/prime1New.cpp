#include <stdio.h>
bool prime[40000];

int isPrime(int k)
{
	int i;
	if (k<2)return 0;
	if (k==2)return 1;
	if (k%2==0)return 0;
	for (i=3; i*i<=k; i+=2)
		if (prime[i]==0 && k%i==0)
			return 0;
	return 1;
}

int main()
{
	int i, j, k, kase, m, n, flag=0;
	for (i=2; i*i<40000; i++)
		if (prime[i] == 0)
			for (j=i*i; j<40000; j+=i)
				prime[j] = 1;
	
	scanf ("%d",&kase);

	while (kase--)
	{
		if (flag)
			puts("");
		else
			flag = 1;
		scanf ("%d%d",&m,&n);
		for (k=m; k<=n; k++)
			if (isPrime(k))
				printf ("%d\n",k);
	}
	return 0;
}