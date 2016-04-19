#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int main()
{
//	freopen("in.txt","r",stdin);
	int tCase = 0, kase;
	scanf ("%d",&kase);

	while (kase--)
	{
		int limit, input[100], i;
		scanf ("%d",&limit);
		for (int p=0; p<limit; p++)
			scanf ("%d",&input[p]);

		sort(input,input+limit);
		int right=input[limit-1], left = input[0], lCurr = 1, rCurr = limit-2, ans = right-left, flag = 1;
		for (i=0;; i++)
		{
			if (lCurr>rCurr)
				break;
			if (flag)
			{
				if (abs(right-input[lCurr]) > abs(left-input[lCurr]))
				{
					if (abs(right-input[lCurr]) > abs(right-input[rCurr]))
					{
						ans += abs(right-input[lCurr]);
						right = input[lCurr];
						lCurr++;
						flag = 0;
					}
					else
					{
						ans += abs(right-input[rCurr]);
						right = input[rCurr];
						rCurr--;
						flag = 1;
					}
				}
				else
				{
					if (abs(left-input[lCurr]) > abs(left-input[rCurr]))
					{
						ans += abs(left-input[lCurr]);
						left = input[lCurr];
						lCurr++;
						flag = 0;
					}
					else
					{
						ans += abs(left-input[rCurr]);
						left = input[rCurr];
						rCurr--;
						flag = 1;
					}
				}
			}
			else
			{
				if (abs(right-input[rCurr]) > abs(left-input[rCurr]))
				{
					if (abs(right-input[rCurr]) > abs(right-input[lCurr]))
					{
						ans += abs(right-input[rCurr]);
						right = input[rCurr];
						rCurr--;
						flag = 1;
					}
					else
					{
						ans += abs(right-input[lCurr]);
						right = input[lCurr];
						lCurr++;
						flag = 0;
					}
				}
				else
				{
					if (abs(left-input[rCurr]) > abs(left-input[lCurr]))
					{
						ans += abs(left-input[rCurr]);
						left = input[rCurr];
						rCurr--;
						flag = 1;
					}
					else
					{
						ans += abs(left-input[lCurr]);
						left = input[lCurr];
						lCurr++;
						flag = 0;
					}
				}
			}
		}
		printf ("Case %d: %d\n", ++tCase, ans);
	}

	return 0;
}