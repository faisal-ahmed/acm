#include <stdio.h>
#include <math.h>

#define FOR(i,a,b) for (i=a; i<b; i++)

int main()
{
	int i, input, kase;
	double value = 0.0;

	scanf ("%d",&kase);

	while (kase--)
	{
		value = 0.0;
		scanf ("%d",&input);
		FOR(i,1,input+1) value += log10(i);
		printf ("%d\n",(int)(value)+1);
	}
	
	return 0;
}