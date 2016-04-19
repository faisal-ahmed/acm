#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

#define FOR(i,a,b) for ( (i) = a; (i) < b; (i)++)
#define FORulta(i,a) for ( (i) = a; (i) >= 0; (i)--)

struct smarter
{
	int w, iq, serial;

	bool operator < (smarter X) const
	{
		return w<X.w;
	}
};

int main()
{
	smarter input[1100];
	int i=0, res[1100], parent[1100], j, k, max = 0;

	memset(parent,-1,sizeof (parent));
	FOR(i,0,1100) res[i] = 1;

	i=0;

	while (scanf ("%d%d",&input[i].w,&input[i].iq)==2)
	{
		input[i].serial = i+1;
		i++;
	}
	sort(input,input+i);

	FORulta(j, i-1)
	{
		FOR(k, j+1, i-1)
		{
			if ( input[k].w != input[j].w && input[k].iq < input[j].iq && res[k]+1 > res[j] )
			{
				res[j] = res[k]+1;
				parent[j] = k;
			}
		}
	}

	FOR(j,0,i) if (res[max] < res[j]) max = j;
	printf ("%d\n",res[max]);
	while (max != -1)
	{
		printf ("%d\n",input[max].serial);
		max = parent[max];
	}

	return 0;
}