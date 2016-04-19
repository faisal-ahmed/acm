#include <stdio.h>

int main()
{
	int number;
	unsigned long long int sum[50002];

	sum[0] = 0;
	for ( unsigned long long int i=1; i<50002; i++)
	{
		sum[i] = sum[i-1] + i*i*i;
	}

	while (scanf ("%d",&number)==1)
	{
		printf ("%llu\n",sum[number]);
	}

	return 0;
}