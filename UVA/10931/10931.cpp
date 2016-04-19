#include <stdio.h>

int main()
{
	int input;

	while (scanf ("%d",&input)==1 && input>0)
	{
		printf ("The parity of ");
		int temp = input, res[32], res_counter = 0, one = 0;
		while (temp!=0)
		{
			if ( (res[res_counter] = temp%2) == 1 )
				one++;
			res_counter++;
			temp /= 2;
		}
		for (int i = res_counter-1; i>=0; i--)
			printf ("%d",res[i]);
		printf (" is %d (mod 2).\n",one);
	}

	return 0;
}