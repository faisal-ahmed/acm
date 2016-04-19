#include <stdio.h>
#include <ctype.h>

int main()
{
	int kase;
	scanf ("%d",&kase);
	getchar();

	for (int i=1; i<=kase; i++)
	{
		char input[200];
		gets (input);
		printf ("Case %d: ",i);
		for (int j=0; input[j]!='\0'; j++)
		{
			int repeat = 0, m=j+1;
			while ( isdigit(input[m]) )
			{
				repeat = repeat*10 + input[m]-'0';
				m++;
			}
			while (repeat--)
				printf ("%c",input[j]);
			j = m-1;
		}
		puts("");
	}

	return 0;
}