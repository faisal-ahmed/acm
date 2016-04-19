#include <stdio.h>
#include <math.h>
bool prime[35000];
int result[35000];

int main()
{
	prime[1] = 1;
	for (int i=4; i<35000; i+=2)
		prime[i] = 1;
	for (int j=3; j*j<35000; j+=2)
	{
		if (prime[j] == 0)
		{
			for (int k=j*j; k<35000; k+=j)
				prime[k] = 1;
		}
	}
	for (int m=4; m<35000; m++)
	{
		int z = m;
		z = ceil(z/2);
		for (int n=m-1; n>=z; n--)
		{
			if (prime[n] == 0)
			{
				if (prime[m-n]==0)
					result[m]++;
			}
		}
	}
	int input;

	while (scanf ("%d",&input)==1 && input)
	{
		printf ("%d\n",result[input]);
	}

	return 0;
}