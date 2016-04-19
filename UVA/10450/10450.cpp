#include <stdio.h>

int main()
{
	unsigned long long int value[52];
	int input,kase, prin=0;
	value[0] = 2;
	value[1] = 3;
	for (int i=2; i<51; i++)
		value[i] = value[i-1]+value[i-2];
	scanf ("%d",&kase);
	while (kase--)
	{
		scanf ("%d",&input);
		printf ("Scenario #%d:\n%llu\n\n",++prin,value[input-1]);
	}
	return 0;
}