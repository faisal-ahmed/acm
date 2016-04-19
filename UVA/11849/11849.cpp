#include <stdio.h>
#include <map>
using namespace std;

int main()
{
	int a, b;

	while (scanf ("%d%d",&a,&b)==2 && (a||b))
	{
		map<int,bool> first;
		int c, count = 0, i;
		for (i=0; i<a; i++) { scanf ("%d",&c); first[c] = 0; }
		for (i=0; i<b; i++) { scanf ("%d",&c); if (first.find(c) != first.end()) count++; }
		printf ("%d\n",count);
	}

	return 0;
}