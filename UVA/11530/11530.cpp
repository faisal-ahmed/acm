#include <stdio.h>

int main()
{
	int kase, limit[27]={0,1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,4,1,2,3,1,2,3,4};
	scanf ("%d",&kase);
	getchar();

	for (int i=1; i<=kase; i++)
	{
		char input[110];
		int res = 0;
		gets(input);
		for (int j=0; input[j]!='\0'; j++)
		{
			if (input[j] == ' ')
				res++;
			else
				res += limit[input[j] - 'a' + 1];
		}
		printf ("Case #%d: %d\n",i,res);
	}

	return 0;
}