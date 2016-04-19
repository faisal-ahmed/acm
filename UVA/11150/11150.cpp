#include <stdio.h>

int main()
{
	int input;

	while (scanf ("%d",&input)==1)
	{
		int total=0, newB = 0;
		while (input>=3)
		{
			newB = 0;
			while (input>=3)
			{
				total += 3;
				input-=3;
				newB++;
			}
			input += newB;
		}
		if (input==2)
			total += (input+1);
		else
			total += input;
		printf("%d\n",total);
	}

	return 0;
}