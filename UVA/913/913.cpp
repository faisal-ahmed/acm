#include <stdio.h>

int main()
{
	unsigned long long int N;

	while (scanf ("%llu",&N)==1)
	{
		unsigned long long int number = ((N+1)*(N+1))/2, result=0;
		result = 3*number-9;
		printf ("%llu\n",result);
	}

	return 0;
}