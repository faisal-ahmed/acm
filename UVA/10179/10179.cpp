#include <stdio.h>

int phi(int n)
{
	int ans = n-1;
	for (int i=2; i*i<=n; ++i)
	{
		if (n%i==0)
		{
			ans = ans - ans/i;
			while (n%i==0)
				n/=i;
		}
	}
	if (n>1)
		ans = ans - ans/n;
	return ans;
}

int main()
{
	int input;

	while (scanf ("%d",&input)==1 && input>0)
	{
		if (input!=1)
			printf ("%d\n", phi(input));
		else
			printf ("1\n");
	}

	return 0;
}