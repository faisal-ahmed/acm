#include <stdio.h>
#include <string>
using namespace std;

#define FOR(i,a,b) for (i=a; i<b; i++)

int main()
{
	int n, tCase = 0, i, j, k, input[100005], m;
	char a[15],b[15], ans[10];
	
	while (scanf ("%d",&n)==1 && n)
	{
		FOR(i,0,n) 
		{ 
			scanf ("%d",&input[i]);
			if (i!=0 && input[i-1]+1 == input[i]) input[i-1] = 1;
		}
		printf ("Case %d:\n",++tCase);
		int count = 0;
		FOR(i,0,n) 
		{
			m=0;
			if (count && input[i] != 1) 
			{ 
				sprintf(a,"%d",input[i]);
				sprintf(b,"%d",input[i]-count);
				for (j=0; a[j] != NULL; j++) if (a[j] != b[j]) break;
				for (k=j; a[k] != NULL; k++) ans[m++] = a[k];
				ans[m] = NULL;
				printf ("0%d-%s\n",input[i]-count,ans); 
				count = 0; 
			}
			else if (!count && input[i] != 1) printf ("0%d\n",input[i]);
			else count++;
		}
		puts("");
	}

	return 0;
}