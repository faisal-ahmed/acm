#include <stdio.h>

int check[10000];

int main()
{
	check[0] = check[1] = 1;
	int i, n, input, k;

	for (i=4; i<10000; i++)
	{
		n = i*i;
		if (n < 100)
		{
			k = (n%10)+(int)(n/10);
			if ( k*k == n)
				check[i] = 1;
		}
		else if (n >= 100 && n < 10000)
		{
			k = (n%100)+(int)(n/100);
			if ( k*k == n)
				check[i] = 1;
		}
		else if (n >= 10000 && n < 1000000)
		{
			k = (n%1000)+(int)(n/1000);
			if ( k*k == n)
				check[i] = 1;
		}
		else if (n >= 1000000 && n < 100000000)
		{
			k = (n%10000)+(int)(n/10000);
			if ( k*k == n)
				check[i] = 1;
		}
	}

	while (scanf ("%d",&input)==1)
	{
		int l, output;
		if (input==2)
		{
			for (l=0; l<10; l++)
			{
				output = l*l;
				if (check[l] == 1)
				{
					if (output<10)
						printf ("0%d\n",output);
					else
						printf ("%d\n",output);
				}
			}
		}
		else if (input==4)
		{
			printf ("0000\n0001\n");
			for (l=10; l<100; l++)
			{
				output = l*l;
				if (check[l] == 1)
				{
					if (output<10)
						printf ("000%d\n",output);
					else if (output<100)
						printf ("00%d\n",output);
					else if (output<1000)
						printf ("0%d\n",output);
					else
						printf ("%d\n",output);
				}
			}
		}
		else if (input==6)
		{
			printf ("000000\n000001\n");
			for (l=100; l<1000; l++)
			{
				output = l*l;
				if (check[l] == 1)
				{
					if (output<10)
						printf ("00000%d\n",output);
					else if (output<100)
						printf ("0000%d\n",output);
					else if (output<10000)
						printf ("00%d\n",output);
					else if (output<100000)
						printf ("0%d\n",output);
					else
						printf ("%d\n",output);
				}
			}
		}
		else if (input==8)
		{
			printf ("00000000\n00000001\n");
			for (l=1000; l<10000; l++)
			{
				output = l*l;
				if (check[l] == 1)
				{
					if (output<10)
						printf ("0000000%d\n",output);
					else if (output<100)
						printf ("000000%d\n",output);
					else if (output<10000)
						printf ("0000%d\n",output);
					else if (output<100000)
						printf ("000%d\n",output);
					else if (output<1000000)
						printf ("00%d\n",output);
					else if (output<10000000)
						printf ("0%d\n",output);
					else
						printf ("%d\n",output);
				}
			}
		}
	}

	return 0;
}