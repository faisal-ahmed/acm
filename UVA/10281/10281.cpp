#include <stdio.h>
#include <ctype.h>

int main()
{
	char i[500];
	int speed = 0, iniTime, totalTime, remainTime, k = 8, flag = 1, speed2, m, speedFlag;
	double dis = 0.0;

	while (gets(i))
	{
		k=8;
		if (!flag)
		{
			totalTime = ((i[0]-'0')*10+i[1]-'0')*3600 + ((i[3]-'0')*10+i[4]-'0')*60 +((i[6]-'0')*10+i[7]-'0');
			remainTime = totalTime - iniTime;
			dis += ((double)(speed*remainTime)/3600.0);
			iniTime = totalTime;
		}
		else
			iniTime = ((i[0]-'0')*10+i[1]-'0')*3600 + ((i[3]-'0')*10+i[4]-'0')*60 +((i[6]-'0')*10+i[7]-'0');

		if (i[k] != NULL)
		{
			speed2 = speedFlag = 0;
			while (i[k])
			{
				if (isdigit(i[k]))
				{
					speed2 *= 10;
					speed2 += (i[k] - '0');
					speedFlag = 1;
				}
				k++;
			}
			if (speedFlag)
				speed = speed2;
			else
			{
				for (m=0; m<8; m++)
					printf ("%c",i[m]);
				printf (" %.2lf km\n",dis);
			}
		}
		else
		{
			for (m=0; m<8; m++)
				printf ("%c",i[m]);
			printf (" %.2lf km\n",dis);
		}
		flag = 0;
	}

	return 0;
}
