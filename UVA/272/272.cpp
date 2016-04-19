#include <stdio.h>

int main()
{
//	freopen("out.txt","w",stdout);
	char input[1000];
	int flag = 1;
	while (gets(input))
	{
		int i;
		for ( i=0; input[i]!='\0';i++)
		{
			if (input[i]=='"')
			{
				if (flag)
				{
					printf ("``");
					flag = 0;
				}
				else
				{
					printf ("''");
					flag = 1;
				}
			}
			else
				printf ("%c",input[i]);
		}
		puts("");
	}
	return 0;
}