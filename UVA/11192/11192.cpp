#include <stdio.h>
#include <string.h>

int main()
{
//	freopen("out.txt","w",stdout);
//	freopen("in.txt","rb",stdin);

	int G_input;

	while (scanf("%d",&G_input) && G_input!=0)
	{
		getchar();
		char string[105];
		gets(string);
		int  m = strlen(string),count = 1, loop, k=0, flag=1,G = m/G_input, i = G;

		while (1)
		{
			for (loop = i-1; loop>=k; loop--)
			{
				if (loop>=m)
				{
					flag = 0;
					break;
				}
				printf ("%c",string[loop]);
			}
			if (!flag)
				break;
			i+=G;
			k += G;
			count++;
		}
		puts("");
	}

	return 0;
}