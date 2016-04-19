#include <stdio.h>

#define FOR(i,a,b) for (i=a; i<b; i++)
typedef long long LL;

LL f(LL day)
{
	LL low = 1, hi = 1, mid;
	hi *= (1<<30);

	while (hi-low>1)
	{
		if (hi <= low) break;
		mid = (hi+low)/2;
		if ((mid*(mid+1)/2) > day && mid-1>low) hi = mid-1;
		else if ((mid*(mid+1)/2) < day && mid+1<hi) low = mid+1;
		else break;
	}
	if ((low*(low+1)/2) == day) return low;
	if ((hi*(hi+1)/2) == day) return hi;
	while ((low*(low+1)/2) < day) low++;
	return low;
}

int main()
{
	LL s, d;

	while (scanf ("%lld%lld",&s,&d)==2)
	{
		d += (s*(s-1)/2);
		printf ("%lld\n",f(d));
	}

	return 0;
}

