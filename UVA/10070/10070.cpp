#include <stdio.h>
#include <string.h>

int isDevide(char input[], int size, int digit)
{
	int temp = 0, limit = size, i = 0;
	while (limit--)
	{
		temp *= 10;
		temp += (input[i] - '0');
		i++;
		temp %= digit;
	}
	if (temp == 0)
		return 1;
	else
		return 0;
}

int main()
{
	char input[1000], newline = 0;

	while (scanf ("%s",input)==1)
	{
		if (newline)
			puts("");
		else
			newline=1;
		bool flag = 1, isleap = 0;
		int size = strlen(input);
		if (isDevide(input,size,400))
		{
			flag = 0;
			printf ("This is leap year.\n");
			isleap = 1;
		}
		if (flag)
		{
			if (isDevide(input,size,4) && !isDevide(input,size,100))
			{
				printf ("This is leap year.\n");
				flag = 0;
				isleap = 1;
			}
		}
		if (isDevide(input,size,15))
		{
			printf ("This is huluculu festival year.\n");
			flag = 0;
		}
		if (isDevide(input,size,55) && isleap)
		{
			printf ("This is bulukulu festival year.\n");
			flag = 0;
		}
		if (flag)
			printf ("This is an ordinary year.\n");
	}

	return 0;
}