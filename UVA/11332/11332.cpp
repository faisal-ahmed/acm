#include <stdio.h>

int main()
{
	int input;

	while (scanf ("%d",&input)==1 && input>0)
	{
		int temp = input, res = 0;

		while (1)
		{
			while (temp!=0)
			{
				res += temp%10;
				temp/=10;
			}
			if (res < 10)
				break;
			temp = res;
			res = temp%10;
			temp/=10;
		}
		printf ("%d\n",res);
	}

	return 0;
}