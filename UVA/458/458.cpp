#include <stdio.h>

int main()
{
	char input[500000];

	while (gets(input))
	{
		int i;
		for (i=0; input[i] != '\0'; i++)
			printf ("%c",(input[i]-7));
		puts("");
	}

	return 0;
}