#include <stdio.h>

int main()
{
	int input;

	while (scanf ("%d",&input)==1 && input>=0)
	{
		int res[50],i,j,temp;
		if (input==0)
			printf ("0\n");
		else
		{
			for (i=0;;i++)
			{
				if (input==0)
					break;
				temp = input%3;
				res[i] = temp;
				input/=3;
			}
			for (j=i-1; j>=0; j--)
				printf ("%d",res[j]);
			puts("");
		}
	}

	return 0;
}