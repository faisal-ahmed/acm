#include <stdio.h>
#include <string.h>

#define FOR(i,a,b) for (i=a; i<b; i++)

char input[50010];

int main()
{
	int kase, tCase = 0;
	scanf ("%d",&kase);
	getchar();
	
	while (kase--)
	{
		printf ("Square %d:\n",++tCase);
		int q, i, r1, c1, r2, c2, j, size, p;
		scanf ("%s%d",input,&q);
		getchar();
		size = strlen(input);
		FOR(p,0,q)
		{
			char output[102][105];
			printf ("Query %d:\n",p+1);
			scanf ("%d%d%d%d",&r1,&c1,&r2,&c2);
			FOR(i,r1,r2+1)
			{
				FOR(j,c1,c2+1)
				{
					int r = i, c = j;
					if (r > size) r = size-(r%size);
					if (c > size) c = size-(c%size);
					if (c>=r) output[i-r1][j-c1] = input[r-1];
					else output[i-r1][j-c1] = input[c-1];
				}
				output[i-r1][j-c1] = NULL;
			}
			FOR(j,0,r2+1-r1) printf ("%s\n",output[j]);
		}
		puts("");
	}

	return 0;
}