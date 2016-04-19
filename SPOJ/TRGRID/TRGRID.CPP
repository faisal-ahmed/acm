#include <stdio.h>

int main()
{
	int kase, r, c;
	scanf ("%d",&kase);
	while (kase--)
	{
		scanf ("%d%d",&r,&c);
		if (r%2==0)
		{
			if (c >= r) printf ("L\n");
			else if (c%2==0) printf ("U\n");
			else printf ("D\n");
		}
		else
		{
			if (c >= r) printf ("R\n");
			else if (c%2==0) printf ("U\n");
			else printf ("D\n");
		}
	}

	return 0;
}
