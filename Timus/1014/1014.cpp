#include <stdio.h>

int main()
{
	int input, pos=49, string[50];
	scanf ("%d",&input);

	if (input == 0)
		printf ("10\n",input);
	else if (input < 10)
		printf ("%d\n",input);
	else
	{
		for (int i=9; i>=2; i--)
		{
			while (input%i==0)
			{
				if (pos==-1 || input==1)
					break;
				string[pos] = i;
				input/=i;
				pos--;
			}
			if (pos==-1 || input==1)
				break;
		}
		if (input!=1)
			printf ("-1\n");
		else
		{
			for (int j=pos+1; j<50; j++)
				printf ("%d",string[j]);
			puts("");
		}
	}

	return 0;
}
