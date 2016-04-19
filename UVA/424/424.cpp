#include <stdio.h>
#include <string.h>

int main()
{
	char input[105][105];
	int k = 0, res = 0, i, j, count[105], high = 0, fres[200], m = 0, p;

	while (gets(input[k]))
	{
		count[k] = strlen(input[k]);
		if (high<count[k])
			high = count[k];
		if (input[k][0]=='0')
			break;
		k++;
	}

	for (i=1;i<=high;i++)
	{
		for (j=0;j<k;j++)
		{
			if ((count[j]-i)>=0)
				res += (input[j][count[j]-i] - '0');
		}

		if (res!=0)
		{
			fres[m] = res%10;
			res /= 10;
			m++;
		}
		else
		{
			fres[m] = 0;
			m++;
		}
	}
	if (res!=0)
		printf ("%d",res);
	for (p=m-1;p>=0;p--)
		printf ("%d",fres[p]);
	puts("");

	return 0;
}
