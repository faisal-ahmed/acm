#include <stdio.h>
int gcd(int a, int b)
{
	if (b==0)
		return a;
	return gcd(b,a%b);
}

int main()
{
	int input,G,i,j;
	while (scanf ("%d",&input)==1 && input)
	{
		G=0;
		for(i=1;i<input;i++)
			for(j=i+1;j<=input;j++)
				G+=gcd(i,j);
		printf ("%d\n",G);
	}
	return 0;
}