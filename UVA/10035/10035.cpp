#include <stdio.h>

int main()
{
	int input1, input2;

	while (scanf ("%d%d",&input1,&input2) == 2 && (input1 != 0 || input2 != 0) )
	{
		int carry = 0, res = 0;
		for (int i = 0; input1 > 0 || input2 >0; i++)
		{
			if ( (input1%10 + input2%10 + res) > 9)
			{
				carry++;
				res = 1;
			}
			else
				res = 0;
			if (input2 != 0)
				input2 /= 10;
			if (input1 != 0)
				input1 /= 10;
		}
		if (carry == 0)
			printf ("No carry operation.\n");
		else if (carry == 1)
			printf ("%d carry operation.\n",carry);
		else
			printf ("%d carry operations.\n",carry);
	}

	return 0;
}