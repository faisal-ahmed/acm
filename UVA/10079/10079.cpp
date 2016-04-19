#include <stdio.h>

int main()
{
	long long int input;

	while (scanf ("%lld",&input)==1 && input>=0)
	{
		printf ("%lld\n",(input*(input+1))/2+1);
	}

	return 0;
}