#include <stdio.h>
#include <math.h>
#include <vector>
using namespace std;

#define FOR(i,a,b) for (i=a; i<b; i++)

double log_b(int n, int base)
{
	return log10(n)/log10(base);
}

int min(int a, int b)
{
	if (a>b) return b; return a;
}

int digit(int n, int base)
{
	int i;
	double ret = 0.0;
	FOR(i,1,n+1) ret += log_b(i,base);
	return (int)(ret)+1;
}

void facBase(int base, vector< pair<int,int> >& ret)
{
	int i, count;
	for (i=2; i*i<=base; i++)
	{
		count = 0;
		while (base%i==0)
		{
			count++;
			base/=i;
		}
		if (count > 0) ret.push_back(make_pair(i,count));
	}
	if (base>1) ret.push_back(make_pair(base,1));
}

int facFactorial(int n, vector< pair<int,int> >& list)
{
	unsigned int ret = 0;
	ret += ((1<<31)-1);
	int i, count, b;
	for (i=0; i<list.size(); i++)
	{
		count = 0;
		b = list[i].first;
		while (b<=n)
		{
			count += (int)(n/b);
			b *= list[i].first;
		}
		ret = min(ret,count/list[i].second);
	}
	return ret;
}

int zero(int n, int base)
{
	vector< pair<int,int> > factor_base;
	facBase(base, factor_base);
	return facFactorial(n, factor_base);
}

int main()
{
	int a, b;

	while (scanf ("%d%d",&a,&b)==2)
	{
		printf ("%d %d\n",zero(a,b),digit(a,b));
	}
	
	return 0;
}
