#include <stdio.h>
#include <ctype.h>

int main()
{
//	freopen("F:\in.txt","r",stdin);
//	freopen("F:\out.txt","w",stdout);
	char input[500], match[35] = {"qwertyuiop[]asdfghjkl;'\\zxcvbnm,./"};
	int flag = 0;

	while (scanf ("%s",input)==1)
	{
		if (flag)
			printf (" ");
		flag = 1;
		for (int i=0; input[i]!= '\0'; i++)
		{
			for (int j=0; j<34 ;j++)
			{
				if (tolower(input[i])==match[j])
				{
					printf ("%c",match[j-2]);
					break;
				}
			}
		}
	}
	puts("");

	return 0;
}