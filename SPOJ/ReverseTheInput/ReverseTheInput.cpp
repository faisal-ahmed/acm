#include <stdio.h>
#include <string.h>
#include <string>
using namespace std;

#define FOR(i,a,b) for ( (i) = (a); (i) < (b); (i)++)
#define FORu(i,a,b) for ( (i) = (a); (i) >= (b); (i)--)
		
char input[1100000];

int main()
{
	int n, i, j, flag = 0;
	scanf ("%d",&n);
	getchar();
	string a, b, c;
	while (gets(input))
	{ 
		a += input;
		a += ' ';
	}
	FORu(i, a.size()-1, 0)
	{
		if (a[i] == ' ' && !b.empty())
		{
			FOR(j,0,n)
			{
				if (!flag)
				{
					printf ("%s",b.c_str());
					flag = 1;
				}
				else printf (" %s",b.c_str());
			}
			b = c;
		}
		else if (a[i] != ' ') b += a[i];
	}
	if (!b.empty()) FOR(j,0,n) 
	{ 
		if (!flag) { printf ("%s",b.c_str()); flag = 1; }
		else printf (" %s",b.c_str());
	}
	puts("");

	return 0;
}