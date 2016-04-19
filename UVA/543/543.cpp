#include <stdio.h>
bool prime[1000010];

int main()
{
	int i, j, k, m;
	prime[1] = 1;
	for (i=4; i<1000010; i+=2)
		prime[i] = 1;
	for (j=3; j*j<1000010; j+=2)
	{
		if (prime[j]==0)
		{
			 for (k=j*j; k<1000010; k+=j)
				 prime[k] = 1;
		}
	}
	prime[2] = 1;
	int input,z;
	while (scanf ("%d",&input)==1 && input)
	{
		for (m=3; m<input; m++)
		{
			if (prime[m]==0)
			{
				if (prime[input-m]==0)
				{
					z=input-m;
					break;
				}
			}
		}
		if (m!=input)
			printf ("%d = %d + %d\n",input,m,z);
		else 
			printf ("Goldbach's conjecture is wrong.\n");
	}

	return 0;
}