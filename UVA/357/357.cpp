#include <stdio.h>
#include <string.h>

long long memo[30100][5], coin[5] = {50,25,10,5,1};

long long f(int n, int limit)
{
	if (n==0) return 1;
	if (n<0) return 0;
	if (memo[n][limit] != -1) return memo[n][limit];

	long long x = 0;

	for (int i=0; i<5; i++)
		if (coin[i] <= coin[limit])
			x += f(n-coin[i],i);
	return memo[n][limit] = x;
}

int main()
{
	int n, test;

	memset(memo,-1,sizeof (memo));

	for (int i=0; i<30010; i++) test = f(i,0);

	memo[0][0] = 1;

	while (scanf ("%d",&n)==1)
	{
		if (memo[n][0] != 1) printf ("There are %lld ways to produce %d cents change.\n",memo[n][0],n);
		else printf ("There is only %d way to produce %lld cents change.\n",memo[n][0],n);
	}

	return 0;
}