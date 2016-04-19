#include <stdio.h>
#include <math.h>


int main()
{
	long long int input;
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);

	while (scanf ("%lld",&input)==1 && input)
	{
	/*	res = 0;
		flag = 1;
		for (i = 1; i <= input; i++)
		{
			if (input%i==0)
			{
				if (flag)
				{
					res=1;
					flag=0;
				}
				else
				{
					res=0;
					flag=1;
				}
			}
		}*/
		if ( ( sqrt(input)-(int)(sqrt(input)) )==0)
			printf ("yes\n");
		else
			printf ("no\n");
	}

	return 0;
}