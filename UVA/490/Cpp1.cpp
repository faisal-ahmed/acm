#include<stdio.h>
#include<string.h>

int main()
{
//	freopen ("in.txt","r",stdin);
//	freopen ("out.txt","w",stdout);
	char input[100], store[100][100];
	int a = -1, limit[100], highest = 0,b,c;

	while (gets(input))
	{
		a++;
		limit[a] = strlen(input);
		for (b = 0; b < limit[a]; b++ )
		{
			store[a][b] = input[b];
		}
		if (highest < limit[a])
		{
			highest = limit[a];
		}
		
	}
	
	for(b = 0; b < highest; b++)
	{
		for(c = a; c >= 0; c--)
		{
			if (b >= limit[c])
			{
				printf (" ");
			}
			else
			{
				printf ("%c",store[c][b]);
			}
		}
		printf ("\n");
	}

	return 0;
}