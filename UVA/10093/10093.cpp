#include <stdio.h>
#include <string.h>
#include <ctype.h>

char input[1000000];
int main()
{
	while (scanf ("%s",input)==1)
	{
		bool flag = 1;
		int highest = 0, value = 0;
		for (int i = 0; input[i] != NULL; i++)
		{
			if (isdigit(input[i]))
			{
				if (highest<(input[i] - '0'))
				{
					highest = input[i] - '0';
				}
				value += (input[i] - '0');
			}
			else if (isupper(input[i]))
			{
				if (highest<(input[i] - 'A' + 10))
				{					
					highest = input[i] - 'A' + 10;
				}
				value += (input[i] - 'A' + 10);
			}
			else if (islower(input[i]))
			{
				if (highest<(input[i] - 'a' + 36))
				{
					highest = input[i] - 'a' + 36;
				}
				value += (input[i] - 'a' + 36);
			}
		}
		if (value != 0)
		{
			for (int j = highest; j<62; j++)
			{
				if (value%j == 0)
				{
					printf ("%d\n",j+1);
					flag = 0;
					break;
				}
			}
		}
		else
		{
			printf ("2\n");
			flag = 0;
		}
		if (flag)
			printf ("such number is impossible!\n");
	}

	return 0;
}