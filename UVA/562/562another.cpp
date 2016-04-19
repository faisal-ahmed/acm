#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int dp[50000];
int main()
{
	int kase, input[200];
	scanf ("%d",&kase);

	while(kase--)
	{
		memset(dp,0,sizeof (dp));
		int limit, sum=0;
		scanf ("%d",&limit);
		if (limit==0)
		{
			printf ("0\n");
			continue;
		}
		for (int i=0; i<limit; i++)
		{
			scanf ("%d",&input[i]);
			sum += input[i];
		}
		int knapsack, high = 0, ans = 0;
		if (sum%2==0)
			knapsack = sum/2;
		else
			knapsack = (int)(sum/2) + 1;
		for (int j=0; j<limit; j++)
		{
			for (int cap = knapsack; cap>=0; cap--)
			{
				if (cap+input[j] > knapsack)
					continue;
				if (dp[cap] + input[j] > dp[cap+input[j]])
				{
					dp[cap + input[j]] = dp[cap] + input[j];
					if (dp[cap + input[j]] > high)
						high = dp[cap + input[j]];
				}
			}
		}
		ans = sum - high;
		printf ("%d\n",abs(ans-high));
	}

	return 0;
}