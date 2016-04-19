#include <stdio.h>

int min(int a, int b)
{
	if (a>b) return b;
	return a;
}

void f(int input, int& res, int n)
{
	int p = n;
	while (p<=input)
	{
		res += (int)(input/p);
		p *= n;
	}
}

int main()
{
	int kase;
	scanf ("%d",&kase);

	while (kase--)
	{
		int two = 0, five = 0, input;
		scanf ("%d",&input);
		f(input,two,2);
		f(input,five,5);
		printf ("%d\n",min(two,five));
	}

	return 0;
}