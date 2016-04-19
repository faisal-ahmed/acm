#include <stdio.h>

int main()
{
	double h,m;

	while (scanf ("%lf:%lf",&h,&m)==2 && (h || m) )
	{
		double i=5.00*h+m/12.00, ans, temp;
		if (i>=m)
			temp = i-m;
		else
			temp = m-i;

		if (temp<=30.00)
			ans = temp*6.00;
		else
		{
			ans = 60.00-temp;
			ans *= 6;
		}
		printf ("%.3lf\n",ans);
	}

	return 0;
}


