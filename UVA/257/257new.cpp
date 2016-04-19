#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char input[250], palin[250];
int check, palinlen;

void subpalin(int start, int finis, int palinlen)
{
	int i, j, k = finis-palinlen+1, n = 0, faltu;
	for (i=start; i<=k; i++)
	{
		n=0;
		faltu = i+palinlen;
		for (j=i; j<faltu; j++)
		{
			if (input[j]!=palin[n])
				break;
			n++;
		}
		if (j>=faltu)
			break;
	}
	if (i>k)
		check++;
}

void Ispalin(int start, int finis)
{
	int i, j = finis, k, m = 0, h=finis-start+1, h1 = start+(int)h/2;
	for (i=start; i<h1; i++)
	{
		if (input[i]!=input[j])
			break;
		j--;
	}
	if ( i >= h1 )
	{
		if (palin[0] != '0')
			subpalin(start, finis, palinlen);
		else
		{
			m=0;
			check++;
			for (k=start; k<=finis; k++)
			{
				palin[m]=input[k];
				m++;
			}
			palinlen = m;
		}
	}
}

int main()
{
//	freopen("F:\in.txt","rb",stdin);
//	freopen("out.txt","w",stdout);
	while (scanf ("%s",input)==1)
	{
		palin[0]='0';
		int len = strlen(input), i, flag = 0, j;
		check = 0;
		for (i=2; i<len; i++)   //koto lenth er palin word
		{
			for (j=0; j<len-i; j++)
			{
				if (check==2)
				{
					flag = 1;
					break;
				}
				else
					Ispalin(j,(j+i));
			}
			if (flag)
				break;
		}
		if (check==2)
			printf ("%s\n",input);
	}

	return 0;
}