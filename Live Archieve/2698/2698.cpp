#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <vector>
#include <map>
#include <string>
#include <queue>
#include <sstream>
using namespace std;

#define FOR(i,a,b) for (i=a; i<b; i++)

struct info
{
	string in;
	int cc;
	info(){}
	info(string a, int b) { in = a; cc = b; }
};

int conCon(const string& a)
{
	int ret = 0, i, max = 0;
	
	FOR(i,0,a.size())
	{
		if ((!isalpha(a[i])) || a[i] == 'a' || a[i] == 'e' || a[i] == 'i' || a[i] == 'o' || a[i] == 'u' || a[i] == 'y' || a[i] == 'A' || a[i] == 'E' || a[i] == 'I' || a[i] == 'O' || a[i] == 'U' || a[i] == 'Y') 
		{ 
			if (max<ret) max = ret;
			ret = 0; 
		}
		else if (isalpha(a[i])) ret++;
	}
	if (max<ret) max = ret;
	return max;
}

int main()
{
	int n, consonent, flag, ret, conF, i, size;
	scanf ("%d",&n);
	getchar();
	char input[205];
	string a, b;
	queue<info> hold;

	while (n--)
	{
		info test;
		flag = 0;
		gets(input);
		if (hold.size() > 10) hold.pop();
		a = input;
		consonent = conCon(a);
		if (consonent>5) flag = 1;
		ret = 0;
		conF = 0;
		size = hold.size();
		FOR(i,0,size)
		{
			test = hold.front();
			hold.pop();
			hold.push(test);
			if (test.in == a) ret++;
			if (ret > 1) flag = 1;
			if (consonent > 4 && test.cc > 4) conF++;
			if (conF > 2) flag = 1;
		}
		hold.push(info(a,consonent));
		if (flag) puts("n");
		else puts("y");
	}

	return 0;
}