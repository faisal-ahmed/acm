#include <stdio.h>

int main()
{
	int n, ans, i;
	scanf ("%d",&n);
	ans = n;
	for (i = 2; i*i <= n; i++) ans += ( (n-i*i)/i + 1);
	printf ("%d\n", ans);
	
	return 0;
}