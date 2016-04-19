#include <stdio.h>
#include <string.h>
char fib[5010][5000];
void add(int first, int second, int terget)
{
	int i,temp=0;
	for (i=4999; fib[first][i] != NULL; i--)
	{
		if (fib[second][i] != NULL)
		{
			temp += (fib[second][i]-'0')+(fib[first][i]-'0');
			fib[terget][i] = temp%10 + '0';
			temp /= 10;
		}
		else
		{
			temp += (fib[first][i]-'0');
			fib[terget][i] = temp%10 + '0';
			temp /= 10;
		}
	}
	while (temp!=0)
	{
		fib[terget][i] = temp%10 + '0';
		temp/=10;
		i--;
	}
}

int main()
{
	int input, i,j=0,k;
	memset(fib,NULL,sizeof (fib));

	fib[0][4999] = '0';
	fib[1][4999] = '1';
	for (i=2; i<5010; i++)
		add(i-1,i-2,i);

	while (scanf ("%d",&input)==1)
	{
		j=0;
		printf ("The Fibonacci number for %d is ",input);
		while (fib[input][j] == NULL)
			j++;
		for (k=j; k<5000; k++)
			printf ("%c",fib[input][k]);
		puts("");
	}

	return 0;
}