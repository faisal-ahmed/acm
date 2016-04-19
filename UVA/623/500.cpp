#include <stdio.h>
char res[1010][5000];
int start[1010];

void fac()
{
	int mul = 0, temp, j;
	res[0][4999] = '1';
	res[0][4998] = NULL;
	start[0] = 4999;
	for (int m=1; m<1010; m++)
	{
		mul++;
		j=4999;
		temp = 0;
		while (res[m-1][j] != NULL)
		{
			temp += (res[m-1][j] -'0')*mul;
			res[m][j] = temp%10+'0';
			temp/=10;
			j--;
		}
		while (temp)
		{
			res[m][j] = temp%10+'0';
			temp/=10;
			j--;
		}
		res[m][j] = NULL;
		start[m] = j+1;
	}
}

void show(int n)
{
	for (int i=start[n]; i<5000; i++)
		printf ("%c",res[n][i]);
	puts("");
}

int main()
{
	fac();
	int n;
	while (scanf ("%d",&n)==1)
	{
		printf ("%d!\n",n);
		show(n);
	}
	return 0;
}
