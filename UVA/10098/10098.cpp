#include <stdio.h>
#include <string.h>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	int kase;
	scanf ("%d",&kase);
	getchar();

	while (kase--)
	{
		char input[15];
		gets(input);
		string a = input;
		sort(a.begin(), a.end());
		printf ("%s\n",a.c_str());
		while (next_permutation(a.begin(), a.end()))
		{
			printf ("%s\n",a.c_str());
		}
		puts("");
	}

	return 0;
}