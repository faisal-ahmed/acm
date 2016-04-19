#include <stdio.h>
bool prime[1200];
int main()
{
	int n, c, list[1150], count = 0, b_line = 0,m,h,p,k;
	prime[1] = 0;
	int i, j, f;
	for (i = 4; i < 1150; i += 2)
		prime[i] = 1;
	for (j = 3; j*j < 1150; j += 2)
	{
		if (prime[j]==0)
		{
			for (f = j*j; f < 1150; f += j)
				prime[f] = 1;
		}
	}

	list[0] = 0;
	for (p=1; p<1150; p++)
	{
		if (prime[p]==0)
			list[p] = ++count;
		else
			list[p] = count;
	}

	while (scanf ("%d%d",&n,&c)==2)
	{
		printf ("%d %d:",n,c);
		if (list[n]%2==0)
		{
			if (c*2 > list[n])
			{
				for (k=1; k<=n; k++)
				{
					if (prime[k]==0)
						printf (" %d",k);
				}
			}
			else
			{
				int bad = (list[n] - c*2)/2, store = c*2;
				for (h=1; h<=n; h++)
				{
					if (bad==0)
					{
						if (prime[h]==0)
						{
							printf (" %d",h);
							store--;
						}
					}
					else if (prime[h]==0)
						bad--;
					if (store==0)
						break;
				}
			}
		}
		else
		{
			if ( (c*2-1) > list[n])
			{
				for (m=1; m<=n; m++)
				{
					if (prime[m]==0)
						printf (" %d",m);
				}
			}
			else
			{
				int bad = (list[n] - c*2+1)/2, store = c*2-1;
				for (h=1; h<=n; h++)
				{
					if (bad==0)
					{
						if (prime[h]==0)
						{
							printf (" %d",h);
							store--;
						}
					}
					else if (prime[h]==0)
						bad--;
					if (store==0)
						break;
				}
			}
		}
		puts("");
		puts("");
	}

	return 0;
}