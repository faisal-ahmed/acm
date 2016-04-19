#include <stdio.h>
#include <string.h>

int main()
{
	unsigned long long dp[5050], i, value, len;
	char input[5050];

	while (gets(input) && input[0] != '0')
	{
		memset(dp,0,sizeof (dp));
		dp[0] = 1;
		if (input[1] != NULL)
		{
			value = ((input[0] - '0')*10 + input[1] - '0');
			if (value<27 && value>0 && (input[1] - '0')>0)
				dp[1] = 2;
			else
				dp[1] = 1;
		}
		i = len = strlen(input);
		for (i=2; i<len; i++)
		{
			value = ((input[i-1] - '0')*10 + input[i] - '0');
			if (value < 27 && value >9)
				dp[i] += dp[i-2];
			if ((input[i] - '0')>0)
				dp[i] += dp[i-1];
		}
		printf ("%llu\n",dp[len-1]);
	}

	return 0;
}