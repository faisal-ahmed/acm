#include <stdio.h>

int main()
{
//	freopen("out.txt","w",stdout);
	unsigned long long int input, calc, kuti = 0, kase = 0, minas;

	while (scanf("%llu",&input)==1)
	{
		kase++;
		printf ("%4d.",(int)kase);
		calc = input;
		minas = kuti = (int)(calc/10000000);

		if (input != 0)
		{
			if (kuti>=10000000)
			{
				printf (" %d kuti",(int)kuti/10000000);
				kuti = kuti%10000000;
				if (kuti > 99999)
				{
					printf (" %d lakh",(int)kuti/100000);
					kuti = kuti%100000;
				}
				if (kuti > 999)
				{
					printf (" %d hajar",(int)kuti/1000);
					kuti = kuti%1000;
				}
				if (kuti > 99)
				{
					printf (" %d shata",(int)kuti/100);
					kuti = kuti%100;
				}
				if (kuti != 0)
				{
					printf (" %d kuti",(int)kuti);
					kuti = 0;
				}
				else
					printf (" kuti");
			}
			else if (kuti>=100000)
			{
				printf (" %d lakh",(int)kuti/100000);
				kuti = kuti%100000;
				if (kuti > 999)
				{
					printf (" %d hajar",(int)kuti/1000);
					kuti = kuti%1000;
				}
				if (kuti > 99)
				{
					printf (" %d shata",(int)kuti/100);
					kuti = kuti%100;
				}
				if (kuti != 0)
				{
					printf (" %d kuti",(int)kuti);
					kuti = 0;
				}
				else
					printf (" kuti");
			}
			else if (kuti>=1000)
			{
				printf (" %d hajar",(int)kuti/1000);
				kuti = kuti%1000;
				if (kuti > 99)
				{
					printf (" %d shata",(int)kuti/100);
					kuti = kuti%100;
				}
				if (kuti != 0)
				{
					printf (" %d kuti",(int)kuti);
					kuti = 0;
				}
				else
					printf (" kuti");
			}
			else if (kuti>=100)
			{
				printf (" %d shata",(int)kuti/100);
				kuti = kuti%100;
				if (kuti != 0)
				{
					printf (" %d kuti",(int)kuti);
					kuti = 0;
				}
				else
					printf (" kuti");
			}
			else if (kuti > 0)
			{
				printf (" %d kuti",(int)kuti);
				kuti = 0;
			}
		
			calc -= minas*10000000;
			if (calc != 0)
			{
				if (calc>=100000)
				{
					printf (" %d lakh",(int)calc/100000);
					calc = calc%100000;
					if (calc > 999)
					{
						printf (" %d hajar",(int)calc/1000);
						calc = calc%1000;
					}
					if (calc > 99)
					{
						printf (" %d shata",(int)calc/100);
						calc = calc%100;
					}
					if (calc != 0)
						printf (" %d\n",(int)calc);
					else
						puts("");
				}
				else if (calc>=1000)
				{	
					printf (" %d hajar",(int)calc/1000);
					calc = calc%1000;
					if (calc > 99)
					{
						printf (" %d shata",(int)calc/100);
						calc = calc%100;
					}
					if (calc != 0)
						printf (" %d\n",(int)calc);
					else
						puts("");
				}
				else if (calc>=100)
				{
					printf (" %d shata",(int)calc/100);
					calc = calc%100;
					if (calc != 0)
						printf (" %d\n",(int)calc);
					else
						puts("");
				}
				else if (calc != 0)
				{
					printf (" %d\n",(int)calc);
				}
			}
			else
				puts("");
		}
		else
			printf (" %d\n",(int)calc);
	}

	return 0;
}