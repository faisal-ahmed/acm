#include <stdio.h>
#include <vector>
#include <string.h>
using namespace std;

int memo[10000][5];

int cal(int value, int limit, const vector<int>& coin)
{
	if (value<0) return 0;
	if (value==0) return 1;
	if (memo[value][limit] != -1) return memo[value][limit];

	__int64 res = 0;
	for (int i=0; i<coin.size(); i++)
		if (coin[i] <= coin[limit])
			res += cal(value-coin[i],i,coin);

	return memo[value][limit] = res;
}

int main()
{
	memset(memo,-1,sizeof (memo));
	int n;
	vector<int> coin;
	coin.push_back(1);
	coin.push_back(5);
	coin.push_back(10);
	coin.push_back(25);
	coin.push_back(50);

	memo[0][4] = 1;
	int hold;
	for (int i=1; i<7491; i++) hold = cal(i,4,coin);

	while (scanf ("%d",&n)==1)
	{
		printf ("%d\n",memo[n][4]);
	}

	return 0;
}