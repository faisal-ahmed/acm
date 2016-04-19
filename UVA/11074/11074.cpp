#include <stdio.h>

void dot(int S, int N, int T)
{
	int k, w, n, m;
	for (k=1; k<=S; k++)
	{
		for (w=1; w<=N; w++)
		{
			for (m=1; m<=T; m++)
				printf ("*");
			for (n=1; n<=S; n++)
				printf (".");
		}
		for (m=1; m<=T; m++)
			printf ("*");
		puts("");
	}
}

void thik(int S, int N, int T)
{
	int i, j, k;
	for (k=1; k<=T; k++)
	{
		i=(T+S)*N+T;
		for (j = 1; j<=i; j++)
			printf ("*");
		puts("");
	}
}

int main()
{
//	freopen("out.txt","w",stdout);
	int S,T,N,i,j,flag,kase = 0;

	while (scanf ("%d%d%d",&S,&T,&N)==3)
	{
		if (S==0 && T==0 && N==0)
			break;
		printf ("Case %d:\n",++kase);
		i=N*2+1;
		flag = 1;
		for (j=1; j<=i; j++)
		{
			if (flag)
			{
				thik(S,N,T);
				flag = 0;
			}
			else
			{
				dot(S,N,T);
				flag = 1;
			}
		}
		puts("");
	}

	return 0;
}