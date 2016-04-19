#include <stdio.h>

int main()
{
	int s, b, tCase = 0;

	while (scanf ("%d%d",&b,&s)==2 && (s||b))
	{
		if (b==1) printf ("Case %d: :-\\\n",++tCase);
		else if (b<=s) printf ("Case %d: :-|\n",++tCase);
		else printf ("Case %d: :-(\n",++tCase);
	}

	return 0;
}