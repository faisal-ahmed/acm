#include <stdio.h>

int main()
{
//	freopen ("out.txt","w",stdout);
	char input[135];

	while (gets (input))
	{
		int i, res = 0, j;
		for (i=0; input[i] != '\0'; i++)
		{
			if (input[i] > 47 && input[i] < 58)
				res += input[i] - '0';
			else if (input[i] == 'b')
			{
				for (j = 1; j<=res; j++)
					printf (" ");
				res = 0;
			}
			else if (input[i] == '!')
			{
				printf ("\n");
			}
			else if (input[i] == ' ')
				printf (" ");
			else
			{
				for (j = 1; j<=res; j++)
					printf ("%c", input[i]);
				res = 0;
			}
		}
		puts("");
	}

	return 0;
}