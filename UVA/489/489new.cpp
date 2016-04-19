#include <stdio.h>
#include <map>
using namespace std;

int main()
{
	int round;

	while (scanf ("%d",&round)==1 && round != -1)
	{
		getchar();
		map<char,char>store, unmatchStore;
		map<char,int>check;
		int i, j, unmatch = 0, k, unic = 0, totalUnic = 0;
		char game[5000], guess[5000];
		gets(game);
		gets(guess);
		for (i=0; game[i] != NULL; i++)
		{
			if (!(store.find(game[i]) != store.end()))
			{
				store[game[i]] = game[i];
				check[game[i]] = 0;
				unic++;
			}
		}
		for (j=0; guess[j] != NULL; j++)
		{
			if (unmatch==7 || totalUnic == unic)
				break;
			if (store.find(guess[j]) != store.end())
			{
				if (check[guess[j]] == 0)
				{
					check[guess[j]] = 1;
					totalUnic++;
				}
			}
			else if (!(unmatchStore.find(guess[j]) != unmatchStore.end()))
			{
				unmatchStore[guess[j]] = guess[j];
				unmatch++;
			}
		}
		printf ("Round %d\n",round);
		if (unmatch==7)
			printf ("You lose.\n");
		else if (totalUnic == unic)
			printf ("You win.\n");
		else
			printf ("You chickened out.\n");
	}

	return 0;
}