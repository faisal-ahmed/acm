#include <stdio.h>
int list[1000];
int main()
{
	int a, b, i, j, temp2, temp3, m=1;

	list[0] = 1;
	for (i=2;i*i*i<=100050000;i++)
	{
		temp2 = i*i*i;
		for (j=i+1;;j++)
		{
			temp3 = j*j;
			if (temp3==temp2)
			{
				list[m++] = temp2;
				break;
			}
			else if (temp3>temp2)
				break;
		}
	}
	while (scanf ("%d%d",&a,&b)==2)
	{
		int count=0, loop;
		for (loop=0;loop < m;loop++)
		{
			if (list[loop] >= a && list[loop] <= b)
				count++;
			else if (list[loop] > b)
				break;
		}
		printf ("%d\n",count);
	}

	return 0;
}