#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
#include <sstream>
using namespace std;

//typedef __int64 LL;

#define UN(v) { SORT(v); v.erase(unique(v.begin(), v.end()),v.end()); }
#define SORT(c) sort((c).begin(),(c).end());
#define FOR(i,a,b) for (i=a; i<b; i++)
#define FORu(i,a,b) for (i=a; i>=b; i--)
#define FORstr(i,a,b) for (i=a; b[i]!=NULL; i++)
#define CL(a,b) memset(a, b, sizeof (a))
#define pb push_back
#define MK make_pair
#define all(v) (v).begin(),(v).end()

const int INF=(1<<30);
//const LL INFL=(1<<62);
const double pi=2.0*acos(0);

int main()
{
	int a[3];

	while (scanf ("%d%d%d",&a[0],&a[1],&a[2])==3 && (a[0] || a[1] || a[2]))
	{
		sort(a,a+3);
		if (a[0]*a[0]+a[1]*a[1] == a[2]*a[2] && a[0] && a[1]) puts("right");
		else puts("wrong");
	}

	return 0;
}