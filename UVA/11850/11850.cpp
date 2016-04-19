#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int n;
	
	while (scanf ("%d",&n)==1 && n)
	{
		vector<int>input;
		int a, i, flag = 0;
		for (i=0; i<n; i++) { scanf ("%d",&a); input.push_back(a); }
		sort(input.begin(), input.end());
		for (i=1; i<input.size(); i++) if (input[i] - input[i-1] > 200) { flag = 1; break; }
		if (((1422-input[i-1])*2) > 200) flag = 1;
		if (flag) puts("IMPOSSIBLE");
		else puts("POSSIBLE");
	}

	return 0;
}