#include <stdio.h>

int main()
{
	int kase;
	scanf ("%d",&kase);

	while (kase--)
	{
		int input[1050], value = 0, i, limit, count = 0, j, ave = 0;
		scanf ("%d",&limit);
		for (i=0; i<limit; i++)
		{
			scanf ("%d",&input[i]);
			value += input[i];
		}
		ave = value/limit;
		for (j=0; j<limit; j++)
		{
			if (input[j] > ave)
				count++;
		}
		printf ("%.3lf%c\n",(double)(count*100)/limit,'%');
	}

	return 0;
}