#include <stdio.h>
#include <map>
#include <string.h>
using namespace std;

map<int,__int64>memo[6100];

int coin[] = {1, 2, 4, 10, 20, 40, 100, 200, 400, 1000, 2000};

__int64 go(int n, int m)
{
	if (n<0) return 0;
	if (n==0) return 1;
	if (memo[n].find(m) != memo[n].end()) return memo[n][m];
	memo[n][m] = 0;
	for (int i=0; i<11; i++)
		if (coin[i] <= m)
			memo[n][m] += go(n-coin[i], coin[i]);
	return memo[n][m];
}

int main()
{
	int x, a, b;
	__int64 hold;
	for (int i=1; i<6020; i++)
		hold = go(i,i);
	while (scanf ("%d.%d",&a,&b)==2 && (a||b) )
	{
		x=a;
		if (b>99)
			x+=(int)(b/100);
		b = b%100;
		a=x;
		x*=100;
		x+=b;
		if (x%5==0)
			if (b<10) printf ("%3d.0%d%17I64d\n", a, b, memo[x/5][x/5]);
			else printf ("%3d.%d%17I64d\n", a, b, memo[x/5][x/5]);
		else
			if (b<10) printf ("%3d.0%d                0\n", a, b);
			else printf ("%3d.%d                0\n", a, b);
	}
	return 0;
}