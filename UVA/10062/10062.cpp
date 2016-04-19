#include <stdio.h>
#include <string.h>

int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);


	char input[1005],res1[127], flag = 0;

	int k;
	for (k=0;k<127;k++)
		res1[k] = k;
	
	while (gets(input))
	{
		if (flag)
			puts("");
		flag++;
		int i, m, n, greatest=0,count = 0, res2[127], check = 1;
		memset(res2,0,sizeof(res2));
		for (i=0; input[i]!='\0'; i++)
		{
			if (++res2[(int)input[i]] > greatest)
				greatest = res2[(int)input[i]];
		}
		while (check <= greatest)
		{
			for (m=126; m>=0; m--)
			{
				if (res2[m]==check)
				{
					printf ("%d %d\n",res1[m],res2[m]);
					for (n=m-1; n>=0; n--)
					{
						if (res2[n]==res2[m])
						{
							printf ("%d %d\n",res1[n],res2[n]);
							res2[n]=0;
						}
					}
					res2[m] = 0;
				}
			}
			check++;
		}
	}

	return 0;
}