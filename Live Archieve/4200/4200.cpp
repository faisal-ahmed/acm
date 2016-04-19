#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <string>
#include <vector>
using namespace std;

#define FOR(i,a,b) for (i=a; i<b; i++)
#define CL(a,b) memset(a,b,sizeof(a))

int main()
{
	int n, tCase = 0;

	while (scanf ("%d",&n)==1 && n)
	{
		getchar();
		string ans, temp;
		char input[101][110], output[101][110];
		int numr[10], letter[56], test = 0;
		CL(numr,0);
		CL(letter,0);
		int i, j, flag = 0, sizea, sizeb;
		FOR(i,0,n) scanf ("%s %s",input[i],output[i]);
		FOR(i,0,n)
		{
			if (flag) break;
			if ((sizea = strlen(input[i])) < (sizeb = strlen(output[i]))) { flag = 1; break; }
			FOR(j,1,sizeb-1)
			{
				if (input[i][j] != output[i][j]) { flag = 1; break; }
				else if (isdigit(output[i][j]) && numr[output[i][j] - '0'] != 1) numr[output[i][j] - '0'] = 2;
				else if (isupper(output[i][j]) && letter[output[i][j] - 'A'] != 1) letter[output[i][j] - 'A'] = 2;
				else if (islower(output[i][j]) && letter[output[i][j] - 'a' + 26] != 1) letter[output[i][j] - 'a' + 26] = 2;
				else { flag = 1; break; }
			}
			if (sizea != sizeb)
			{
				if (isdigit(input[i][j]) && numr[input[i][j] - '0'] != 2) numr[input[i][j] - '0'] = 1;
				else if (isupper(input[i][j]) && letter[input[i][j] - 'A'] != 2) letter[input[i][j] - 'A'] = 1;
				else if (islower(input[i][j]) && letter[input[i][j] - 'a' + 26] != 2) letter[input[i][j] - 'a' + 26] = 1;
				else flag = 1;
			}

		}
		printf ("Case %d: ",++tCase);
		if (flag) printf ("I_AM_UNDONE\n");
		else
		{
			temp = "";
			FOR(i,0,10)
			{
				if (numr[i]==0) temp += (i+'0');
				else if (numr[i]==2) { temp += (i+'0'); ans += temp; temp = ""; }
			}
			FOR(i,0,26)
			{
				if (letter[i]==0) temp += (i+'A');
				else if (letter[i]==2) { temp += (i+'A'); ans += temp; temp = ""; }
			}
			FOR(i,26,52)
			{
				if (letter[i]==0) temp += (i+'a'-26);
				else if (letter[i]==2) { temp += (i+'a'-26); ans += temp; temp = ""; }
			}
			if (ans.size() > 0)
			{
				printf ("[");
				printf ("%s]\n",ans.c_str());
			}
			else
			{
				FOR(i,0,10) if (numr[i]==0) { printf ("[%d]\n",i); test = 1; break; }
				if (!test) FOR(i,0,26) if (letter[i]==0) { printf ("[%c]\n",i+'A'); test = 1; break; }
				if (!test) FOR(i,26,52) if (letter[i]==0) { printf ("[%c]\n",i+'a'-26); test = 1; break; }
				if (!test) puts("I_AM_UNDONE");
			}
		}
	}

	return 0;
}