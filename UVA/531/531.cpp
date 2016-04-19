#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>
using namespace std;

#define CL(a,b) memset(a, b, sizeof (a))
#define FOR(i,a, b) for ( (i) = a; (i) < b; (i)++)
#define FORulta(i, a) for ( (i) = a; (i) >= 0; (i)--)

int max(int a, int b)
{
	if (a>b) return a;
	return b;
}

int main()
{
	char test[50];
	while (scanf ("%s",test)==1)
	{
		int res[120][120], i, j, parent[120][120], r = 0, c = 0;
		string a = test;
		vector<string> textOne, textTwo, ansVec;
		textOne.push_back(a);
		while (scanf ("%s",test)==1 && test[0] != '#')
		{
			a = test;
			textOne.push_back(a);
		}
		while (scanf ("%s",test)==1 && test[0] != '#')
		{
			a = test;
			textTwo.push_back(a);
		}

		CL(res,0);
		CL(parent,-1);

		FOR(i, 0, textOne.size())
			FOR(j, 0, textTwo.size())
			{
				if (textOne[i] == textTwo[j])
				{
					res[i+1][j+1] = res[i][j] + 1;
					parent[i+1][j+1] = 1;
				}
				else
				{
					res[i+1][j+1] = max(res[i][j+1], res[i+1][j]);
					parent[i+1][j+1] = 2;
				}
				if (res[r][c] < res[i+1][j+1])
				{
					r = i+1;
					c = j+1;
				}
			}
		while (parent[r][c] != -1)
		{
			if (parent[r][c] == 1)
			{
				ansVec.push_back(textOne[r-1]);
				r = r-1;
				c = c-1;
			}
			else
			{
				if (res[r-1][c] < res[r][c-1]) c = c-1;
				else r = r-1;
			}
			if (r<0 || c<0) break;
		}
		FORulta(i,ansVec.size()-1)
		{
			if (i != ansVec.size()-1) printf (" %s",ansVec[i].c_str());
			else printf ("%s",ansVec[i].c_str());
		}
		puts("");
	}
	return 0;
}
