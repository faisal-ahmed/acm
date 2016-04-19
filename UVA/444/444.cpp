#include <stdio.h>
#include <string.h>

int main()
{
	char input[100000];

	while (gets(input))
	{
		char swap;
		int k, len = k = strlen(input), i, j;
		for (i=0; i<len/2; i++)
		{
			swap = input[--k];
			input[k] = input[i];
			input[i] = swap;
		}
		if ( (input[0]-'0') < 10 && (input[0]-'0') >= 0)
		{
			for (j=0; j<len; j++)
			{
				int m=0;
				if (input[j]=='1')
				{
					m = 100 + (input[++j]-'0')*10 + (input[++j]-'0');
					printf ("%c",m);
				}
				else
				{
					m =  (input[j]-'0')*10 + (input[++j]-'0');
					printf ("%c",m);
				}
			}
			puts("");
		}
		else
		{
			for (j=0; j<len; j++)
			{
				int m = input[j];
				while (m!=0)
				{
					printf ("%d",m%10);
					m/=10;
				}
			}
			puts("");
		}
	}

	return 0;
}