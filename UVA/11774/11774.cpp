#include <stdio.h>

int gcd(int a, int b)
{
	if (b==0)
		return a;
	return gcd(b,a%b);
}

int main()
{
	int kase, tCase = 0; 
	scanf ("%d",&kase);

	while (kase--)
	{
		unsigned __int64 a, b, res;
		scanf ("%I64u%I64u",&a, &b);
		res = a+b;
		printf ("Case %d: %I64u\n",++tCase, (unsigned __int64)(res/gcd(a,b)));
	}

	return 0;
}