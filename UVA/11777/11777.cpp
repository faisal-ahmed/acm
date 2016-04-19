#include <stdio.h>
#include <algorithm>
using namespace std;

int main()
{
	int kase, tCase = 0;
	scanf ("%d",&kase);

	while (kase--)
	{
		int res = 0, ct[5], input;
		for (int i=0; i<4; i++)
		{
			scanf ("%d",&input);
			res += input;
		}
		for (int j=0; j<3; j++)
			scanf ("%d",&ct[j]);
		sort(ct,ct+3);
		res += (int)((ct[1]+ct[2])/2);
		if (res>=90)
			printf ("Case %d: A\n",++tCase);
		else if (res>=80)
			printf ("Case %d: B\n",++tCase);
		else if (res>=70)
			printf ("Case %d: C\n",++tCase);
		else if (res>=60)
			printf ("Case %d: D\n",++tCase);
		else
			printf ("Case %d: F\n",++tCase);
	}

	return 0;
}