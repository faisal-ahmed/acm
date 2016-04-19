#include <stdio.h>
#include <ctype.h>

int main()
{
	char input[500000];
	
	while (gets(input))
	{
		int i, counter=0, j;

		if (input[1]!='\0')
		{
			for (i=0; input[i] != '\0'; i++)
			{
				if (isalpha(input[i]))
				{
					counter++;
					for (j=i+1; isalpha(input[j]) && input[j] != '\0'; j++)
					{
					}
					i=j-1;
				}
			}
		}
		printf ("%d\n",counter);
	}

	return 0;
}