#include <stdio.h>

int main()
{
	char input[25];

	while (gets(input))
	{
		int flag = 0;
		for (int i=0; input[i]!='\0'; i++)
		{
			if (flag)
			{
				if ( (input[i]=='R') && !(input[i-1]=='R') )
					printf ("6");
				else if ( (input[i]=='M' || input[i]=='N') && !(input[i-1]=='M' || input[i-1]=='N') )
					printf ("5");
				else if ( (input[i]=='L') && !(input[i-1]=='L') )
					printf ("4");
				else if ( (input[i]=='D' || input[i]=='T') && !(input[i-1]=='D' || input[i-1]=='T') )
					printf ("3");
				else if ( (input[i]=='C' || input[i]=='G' || input[i]=='J' || input[i]=='K' || input[i]=='Q' || input[i]=='S' || input[i]=='X' || input[i]=='Z') && !(input[i-1]=='C' || input[i-1]=='G' || input[i-1]=='J' || input[i-1]=='K' || input[i-1]=='Q' || input[i-1]=='S' || input[i-1]=='X' || input[i-1]=='Z') )
					printf ("2");
				else if ( (input[i]=='B' || input[i]=='F' || input[i]=='P' || input[i]=='V') && !(input[i-1]=='B' || input[i-1]=='F' || input[i-1]=='P' || input[i-1]=='V') )
					printf ("1");
			}
			else
			{
				flag = 1;
				if (input[i]=='R')
					printf ("6");
				else if (input[i]=='M' || input[i]=='N')
					printf ("5");
				else if (input[i]=='L')
					printf ("4");
				else if (input[i]=='D' || input[i]=='T')
					printf ("3");
				else if (input[i]=='C' || input[i]=='G' || input[i]=='J' || input[i]=='K' || input[i]=='Q' || input[i]=='S' || input[i]=='X' || input[i]=='Z')
					printf ("2");
				else if (input[i]=='B' || input[i]=='F' || input[i]=='P' || input[i]=='V')
					printf ("1");
			}
		}
		puts("");
	}

	return 0;
}