#include <stdio.h>
#include <math.h>

int prime[2000000], prime_use[2000000], r = 0;

int main()
{
//	freopen ("in.txt","rb",stdin);
//	freopen ("out.txt","w",stdout);
//	primegen();

//	prime[0] = 1;
	prime[1] = 0;
	int n = 2000000, a, f, j, k;
	for (a = 4; a < n; a+=2)
		prime[a] = 1;
	for (f = 3; f*f < n; f+=2)
	{
		if (prime[f]==0)
		{
			for (j = f*f; j < n; j+=f)
				prime[j] = 1;
		}
	}
	for (k=2; k < n; k++)
	{
		if (prime[k]==0)
		{
			prime_use[r] = k;
//			printf ("%d ",prime_use[r]);
			r++;
		}
	}
//	printf ("%d ",prime_use[r-1]);

	int input, corect, flag, h,flag2;

	while (scanf ("%d",&input)==1 && input)
	{
		flag = 0;
		if (input>0)
		{
			corect = input;
			printf ("%d = ",input);
			while (corect != 1 && corect != 2147483647)
			{
				flag2=1;
				h=0;
				if (flag)
					printf (" x ");
				flag++;
				int l, m = (int)(sqrt(corect));
				for (l=0; l<m; l++)
				{
					if (corect%prime_use[l]==0)
					{
						printf ("%d",prime_use[l]);                 //kaj kore na for
						corect /= prime_use[l];
						flag2=0;
						break;                                      //685468432      3894707   2147483642
					}
					if (prime_use[l]>corect)
						break;
				}
			/*	if (l>=r)
				{
					for (h=prime_use[r-1]; h<=m; h+=2)       //  prime_use[r-1] = 1999993;
					{
						if (corect%h==0)
						{
							printf ("%d",h);
							corect /= h;
							break;
						}	
					}
				}*/
				if (flag2)
					break;
			}
			if (corect>1)
				printf ("%d",corect);
			puts("");
		}
		else
		{
			corect = -1*(input);
			printf ("%d = -1",input);
			while (corect != 1 && corect != 2147483647)
			{
				flag2=1;
				h=0;
				int l, m = (int)(sqrt(corect));
				for (l=0; l<m; l++)
				{
					if (corect%prime_use[l]==0)
					{
						printf (" x %d",prime_use[l]);
						corect /= prime_use[l];
						flag2=0;
						break;
					}
					if (prime_use[l]>corect)
						break;
				}
		/*		if (l>=r)
				{
					for (h=prime_use[r-1]; h<=m; h+=2)
					{
						if (corect%h==0)
						{
							printf (" x %d",h);
							corect /= h;
							break;
						}	
					}
				}*/
				if (flag2)
					break;
			}
			if (corect>1)
				printf (" x %d",corect);
			puts("");
		}
	}
	return 0;
}