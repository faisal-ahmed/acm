#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
#include <sstream>
using namespace std;

int main()
{
	char kase[1000];
	int k;
	gets(kase);
	stringstream sp(kase);
	sp >> k;

	while (k--)
	{
		int max = 0, len = 0, flag = 1, pres = 0, pos = 0;
		string b;
		char input[1000000];
		gets(input);
		stringstream ss;
		ss << (string)(input);
		while (ss>>b)
		{
			if (flag) { len = b.size(); flag = 0; pres++; continue; }
			if (b.size() == len) pres++;
			else { if (max < pres) max = pres; pres = 1; len = b.size(); }
		}
		if (pres > max) max = pres;
		printf ("%d\n",max);
	}

	return 0;
}