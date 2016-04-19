#include <stdio.h>

char test[5376758]; //bit 43014064
int prime[5000002];

#define chkB(a,n) (a[n>>3]&(1<<(n&7)))
#define setB(a,n) (a[n>>3]|=(1<<(n&7)))

int main()
{
	int kase, input, k = 2, i = 2, j, bit = 3, value = 7;
	prime[0] = 2;/////// 86028121
	prime[1] = 3;
	prime[2] = 5;

	for (i = 4; i<43014064; i+=3) setB(test,i);
	for (i = 12; i<43014064; i+=5) setB(test,i);
	for (i = 2; ((value*value)>>1) < 43014064; i++)
	{
		bit = (value>>1);
		if (!chkB(test,bit)) for (j=((value*value)>>1); j<43014064; j+=value) setB(test,j);
		value += 4;
		bit = (value>>1);
		if (!chkB(test,bit)) for (j=((value*value)>>1); j<43014064; j+=value) setB(test,j);
		value = 6*i+1;
	}

	value = 7;
	for (i = 2; k<5000000; i++)
	{
		bit = (value>>1);
		if (!chkB(test,bit)) prime[++k] = value;
		value += 4;
		bit = (value>>1);
		if (!chkB(test,bit)) prime[++k] = value;
		value = 6*i+1;
	}

//	printf ("%d\n",k);
	scanf ("%d",&kase);
	for (i = 0; i<kase; i++)
	{
		scanf ("%d",&input);
		printf ("%d\n",prime[input-1]);
	}

	return 0;
}

/* 6k+1 or 6k+5 er khetre k is atmost 14338020;  100000000  */
