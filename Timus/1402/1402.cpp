//Permutaion combination string multiplication
#include <stdio.h>
#include <string.h>
int combinRes[30][30];
char perm[25][30], save[50], result[50];

void permut()
{
	int mul = 0;
	perm[0][29] = '1';
	perm[0][28] = NULL;
	for (int i=1; i<23; i++)
	{
		mul++;
		int temp = 0, p=29;
		while (perm[i-1][p] != NULL)
		{
			temp += (perm[i-1][p]-'0')*mul;
			perm[i][p] = temp%10+'0';
			temp /= 10;
			p--;
		}
		while (temp)
		{
			perm[i][p] = temp%10+'0';
			temp/=10;
			p--;
		}
		perm[i][p] = NULL;
	}
}

void combin()
{
	int i, j, k;
	combinRes[0][0] = 1;
	combinRes[0][1] = 0;
	for (k=1; k<25; k++)
	{
		combinRes[k][1] = k;
		combinRes[k][0] = 1;
	}
	for (i=2; i<25; i++)
	{
		for (j=2; j<=i; j++)
			combinRes[i][j] = combinRes[i-1][j-1] + combinRes[i-1][j];
		combinRes[i][j] = 0;
	}
}

void add(int m)
{
	int i=49, temp = 0;
	while (i!=m)
	{
		temp += (save[i]-'0');
		if (result[i] != NULL)
			temp += (result[i]-'0');
		result[i] = temp%10+'0';
		temp/=10;
		i--;
	}
	while (temp)
	{
		if (result[i] != NULL)
			temp += (result[i]-'0');
		result[i] = temp%10+'0';
		temp/=10;
		i--;
	}
}

void multip(char per[], int com)
{
	int temp = 0, p=29, i=49;
	while (per[p] != NULL)
	{
		temp += ((per[p]-'0')*com);
		save[i] = temp%10+'0';
		temp /= 10;
		p--;
		i--;
	}
	while (temp)
	{
		save[i] = temp%10+'0';
		temp/=10;
		i--;
	}
	save[i] = NULL;
	add(i);

}

int main()
{
	memset(result,NULL,sizeof (result));
	permut();
	combin();
	int n;
	scanf ("%d",&n);
	if (n!=1)
	{
		int i, j, m;
		for (i=2; i<=n; i++)
			multip(perm[i],combinRes[n][i]);
		for (m=0; result[m] == NULL; m++){}
		for (j=m; j<50; j++)
			printf ("%c",result[j]);
		puts("");
	}
	else
		printf ("0\n");

	return 0;
}