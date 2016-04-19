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
const double pi=2.0*acos(0);

string list[100005];

int main()
{
	int kase, tCase = 0;
	scanf ("%d",&kase);
	getchar();
 
	while (kase--)
	{
		string temp, a;
		set<string> unik;
		map<string,int> hold;
		int i, j, length = 0, p, q, st = 0, max = 1, min = 1, last = 0;
		char input[160];
		while (gets(input))
		{
			if (input[0]=='E') break;
			FORstr(i,0,input) if (!isalpha(input[i])) input[i] = ' '; 
			stringstream ss(input);
			while (ss>>a) { unik.insert(a); list[st++] = a; }
		}
		p = 1;
		q = st;
		length = unik.size();

		FOR(i,0,st)
		{
			hold[list[i]] = i;
			if (q-p == length-1) break;
			while (hold[list[last]] > last) last++;
			min = last+1;
			max = i+1;
			if (hold.size() == length && max-min <= q-p) { q = max; p = min; }
		}
		printf ("Document %d: %d %d\n",++tCase,p,q);
	}

	return 0;
}