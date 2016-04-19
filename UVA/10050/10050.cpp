#include <stdio.h>
#include <string.h>
int main()
{
	int kase;
	scanf ("%d",&kase);

	while (kase--)
	{
		int day, party, partyHar[120], ans = 0, hDay[3700], value;
		memset(hDay,0,sizeof (hDay));
		scanf ("%d%d",&day, &party);
		for (int i=0; i<party; i++)
			scanf ("%d",&partyHar[i]);
		for (int j=0; j<party; j++)
		{
			value = partyHar[j];
			for (int k=0; value<=day; k++)
			{
				if (value%7 != 0 && value%7 != 6)
				{
					if (hDay[value] == 0)
					{
						hDay[value] = 1;
						ans++;
					}
				}
				value += partyHar[j];
			}
		}
		printf ("%d\n",ans);
	}

	return 0;
}