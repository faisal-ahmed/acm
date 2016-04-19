//marbles
#include <stdio.h>
unsigned long long dp[1000500], result;

int main()
{
	int kase;
	scanf ("%d",&kase);

	while (kase--)
	{
		int n, k, i, j, m, b;
		scanf ("%d%d",&n,&k);
		if (k==1)
		{
			printf ("1\n");
			continue;
		}
		if (n-k==1)
		{
			printf ("%d\n",k);
			continue;
		}
		if (k==2)
		{
			printf ("%d\n",n-k+1);
			continue;
		}
		result = 0;
		int loop = n-k;
		for (m=0; m<=loop; m++)
			dp[m] = m+1;
		for (j=3; j<k; j++)
			for (i=1; i<=loop; i++)
				dp[i] += dp[i-1];
		for (b=0; b<=loop; b++)
			result += dp[b];
		printf ("%llu\n",result);
	}

	return 0;
}