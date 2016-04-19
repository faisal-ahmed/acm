#include <stdio.h>

int main()
{
//	freopen ("out.txt","w",stdout);
	int number, value, space, flag = 1, flag_p;
	while (scanf ("%d",&number)==1 && number)
	{
		flag_p = 0;
		flag = 1;
		space = number;
		while (number--)
		{
			scanf ("%d",&value);
			if (flag_p)
			{
				if (value != 0)
				{
					flag = 0;
					printf (" %d",value);
				}
			}
			else
			{
				if (value != 0)
				{
					flag_p = 1;
					flag = 0;
					printf ("%d",value);
				}
			}
		}
		if (flag)
			printf ("0");
		puts("");
	}
	return 0;
}