#include <stdio.h>

int main()
{
//	freopen("out.txt","r",stdin);
	int kase, input, n, value;

	scanf ("%d",&kase);

	while (kase--)
	{
		value = 0;
		scanf ("%d",&input);
		for (n=2; n*n<=input; n++)
			if (input%n==0)
				value += (n+input/n);
		if ((--n)*n==input)
			value-=n;
		value++;
		printf ("%d\n",value);
	}

	return 0;
}