#include<stdio.h>

int main()
{
	int input_first, one_input, two_input, line, frequency, digit,a;
	//freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	scanf ("%d", & input_first);
	a=0;
	for (int input_set=0; input_set < input_first; input_set++)
	{

		scanf("%d", & one_input);
		scanf ("%d", & two_input);
		for (frequency = 0; frequency < two_input; frequency++)
		{
			if(a!=0)printf ("\n");
			a++;
			for (line = 1; line <= one_input; line++)
			{
				for (digit = 1; digit <= line ; digit++)
				{
					printf ("%d", line);
				}
				printf ("\n");
			}
			for (line = one_input - 1; line >= 1; line--)
			{
				for (digit = 1; digit <= line ; digit++)
				{
					printf ("%d", line);
				}
				printf ("\n");
			}
			
		}
	}
	return 0;
}