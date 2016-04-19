#include <stdio.h>
#include <vector>
#include <math.h>
using namespace std;

#define FOR(i,a,b) for (i=a; i<b; i++)
typedef long long LL;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

LL prime[229144];
LL size;
bool p[3262400];

LL min(LL a, LL b) { if (a>b) return b; return a; }

void ff(LL& ans, LL info[], LL step, LL minimum)
{
	if (step==size) return;
	LL i, m = minimum;
	FOR(i,0,info[step])
	{
		if (i!=0) { m = min(minimum,(info[step]-1)/i); ans += m; }
		ff(ans,info,step+1,m);
	}
}

LL f(LL input)
{
	LL i, b = input, count, ret = 0, k = 0, fac[1000];
//////prime factorization///////
	for (i=0; prime[i]*prime[i] <= b; i++)
	{
		count = 0;
		while (b%prime[i]==0)
		{
			count++;
			b/=prime[i];
		}
		if (count>0) fac[k++] = (count+1);
	}
	if (b>1) fac[k++] = (2);
//////////END////////////
	size = k;
/////All possible divisor (except 1) er base e trailing zeros with the help of a recurrsive function ff()//////
	FOR(i,0,fac[0]) 
	{
		if (i!=0) { ret += (fac[0]-1)/i; ff(ret,fac,1,(fac[0]-1)/i); }
		else ff(ret,fac,1,(1<<30));
	}
////////////////////////////////////////////////////END///////////////////////////////////////////////////////
	return ret;
}

/////////////f() function ta return kore n er all possible base e koita trailing zero thake/////////////////////////////////////////////////

int main()
{
	LL input, i, j;
////////////Prime Generation and storing//////////////////
	for (i=3; i*i<3172300; i+=2) if (!p[i])
		for (j=i*i; j<3172300; j+=(2*i)) p[j] = 1;
	prime[0] = 2;
	j=1;
	for (i=3; i<3172300; i+=2) if (!p[i]) prime[j++] = i;
////////////////////////////END///////////////////////////

	while (scanf ("%lld",&input)==1 && input)
	{
		if (input==1) puts("1 0");
		else printf ("%lld %lld\n",input,f(input));
	}

	return 0;
}