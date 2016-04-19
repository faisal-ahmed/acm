#include <stdio.h>
#include <algorithm>
using namespace std;

int main()
{
	int n, k, s, total, input[1003], add, i, count;

	while (scanf ("%d%d%d",&n,&k,&s) == 3)
	{
		for (i = 0; i<n; i++) scanf ("%d",&input[i]);
		sort(input, input+n);
		total = k*s; count = add = 0;
		for (i = n-1; i>=0; i--) { add += input[i]; count++; if (add >= total) break; }
		printf ("%d\n",count);
	}

	return 0;
}