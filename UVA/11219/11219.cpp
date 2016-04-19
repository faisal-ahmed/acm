#include <stdio.h>

int main()
{
	int dd1, mm1, yy1, dd2, mm2, yy2, kase;
	scanf ("%d",&kase);

	for (int i=1; i<=kase; i++)
	{
		scanf ("%d/%d/%d\n%d/%d/%d", &dd1, &mm1, &yy1, &dd2, &mm2, &yy2);
		if (yy2 > yy1)
			printf ("Case #%d: Invalid birth date\n",i);
		else if (yy2 < yy1)
		{
			if (mm1>mm2)
			{
				if (dd1>dd2)
				{
					if ( (yy1-yy2-1) > 130)
						printf ("Case #%d: Check birth date\n",i);
					else
						printf ("Case #%d: %d",i, yy1-yy2-1);
				}
				if (dd1<dd2)
				{
					mm2++;
					if (mm2>mm1)
				}
			}
			else if (dd2<dd1)
			{
				if (mm2>mm1)
				{
					if ( (yy1-yy2-1) > 130)
						printf ("Case #%d: Check birth date\n",i);
					else
						printf ("Case #%d: %d",i, yy1-yy2-1);
				}
				else
				{
					if ( (yy1-yy2) > 130)
						printf ("Case #%d: Check birth date\n",i);
					else
						printf ("Case #%d: %d",i, yy1-yy2);
				}
			}
			else if (dd2==dd1)
			{
			}
		}
		else if (yy2 == yy1)
		{
			if (mm2>mm1)
				printf ("Case #%d: Invalid birth date\n",i);
			else if (mm2<mm1)
			{
				printf ("0");
			}
			else if (mm2==mm1)
			{
				if (dd2>dd1)
					printf ("Case #%d: Invalid birth date\n",i);
				else
					printf ("0");	
			}
		}
	}

	return 0;
}