#include <stdio.h>

int main()
{
	int kase, tCase = 0;
	scanf ("%d",&kase);

	while (kase--)
	{
		int wSh, wSm, wEh, wEm, mSh, mSm, mEh, mEm, flag = 0, totalMetMinS, totalMetMinE, totalWifMinS, totalWifMinE;
		scanf ("%d:%d %d:%d",&wSh, &wSm, &wEh, &wEm);
		scanf ("%d:%d %d:%d",&mSh, &mSm, &mEh, &mEm);
		totalMetMinS = mSh*60+mSm;
		totalMetMinE = mEh*60+mEm;
		totalWifMinS = wSh*60+wSm;
		totalWifMinE = wEh*60+wEm;
		if (totalWifMinS <= totalMetMinS && totalWifMinE >= totalMetMinS) flag = 1;
		if (totalWifMinE >= totalMetMinE && totalWifMinS <= totalMetMinE) flag = 1;
		if (totalMetMinS < totalWifMinS && totalMetMinE > totalWifMinE) flag = 1;
		if (flag) printf ("Case %d: Mrs Meeting\n",++tCase);
		else printf ("Case %d: Hits Meeting\n",++tCase);
	}

	return 0;
}
