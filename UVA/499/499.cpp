#include <stdio.h>
#include <string.h>

int main()
{
	char input[5000];
	int value[130];

	while (gets(input))
	{
		int highest = 1, flag = 0;
		memset(value,0,sizeof(value));
		for (int i = 0; input[i] != NULL; i++)
		{
			if ( ((int)input[i] > 64 && (int)input[i] < 91) || ((int)input[i] > 96 && (int)input[i] < 123) )
				if (highest<++value[(int)(input[i])])
					highest = value[(int)(input[i])];
		}
		for (int j = 0; j < 130; j++)
		{
			if (value[j] == highest)
			{
				printf ("%c",j);
				flag = 1;
			}
		}
		if (flag)
			printf (" %d",highest);
		puts("");
	}

	return 0;
}