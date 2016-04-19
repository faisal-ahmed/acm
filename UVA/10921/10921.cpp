#include <stdio.h>
#include <ctype.h>

int main()
{
	int alfab[27], value = 2;
	for (int i=1; i<27; i++)
	{
		if (i>0 && i < 4)
			value = 2;
		else if (i>3 && i < 7)
			value = 3;
		else if (i>6 && i < 10)
			value = 4;
		else if (i>9 && i < 13)
			value = 5;
		else if (i>12 && i < 16)
			value = 6;
		else if (i>15 && i<20)
			value = 7;
		else if (i>19 && i<23)
			value = 8;
		else if (i>22)
			value = 9;
		alfab[i] = value;
	}
	char input[35];

	while (gets (input))
	{
		for (int j=0; input[j]!='\0'; j++)
		{
			if ( isalpha(input[j]) )
			{
				printf ("%d",alfab[input[j]-'A'+1]);
			}
			else
				printf ("%c",input[j]);
		}
		puts("");
	}
	return 0;
}