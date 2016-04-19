#include <stdio.h>

int main()
{
	int kase;
	scanf ("%d",&kase);

	while (kase--)
	{
		int farmer;
		long long int  res = 0;
		scanf ("%d",&farmer);
		int input[22][3];
		for (int i=0; i<farmer; i++)
		{
			for (int j=0; j<3; j++)
				scanf ("%d",&input[i][j]);
			res += input[i][0] * input[i][2];
		}
		printf ("%lld\n",res);
	}

	return 0;
}