#include <stdio.h>
#include <ctype.h>
int check[28], kase; 

int main()
{
	char input[5000];

	scanf ("%d",&kase);
	getchar();
	for (int m=0; m<kase; m++)
	{
		gets (input);
		int i;
		for (i=0; input[i]!='\0'; i++)
		{
			if (isalpha(input[i]))
			{
				check[toupper(input[i])-'A'+1]++;
			}
		}
	}
	int high = 0, j, k, zero = 0;

	for (j=0; j<27; j++)
	{
		if (check[j]!=0)
		{
			high = check[j];
			zero = j;
			for (k=j+1; k<27; k++)
			{
				if (high < check[k])
				{
					high = check[k];
					zero = k;
				}
			}
			printf ("%c %d\n",(zero+'A'-1), high);
			check[zero] = 0;
			if (j!=k)
				j--;
		}
	}

	return 0;
}