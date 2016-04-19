#include <stdio.h>

int main()
{
	int m;

	while (scanf ("%d",&m)==1 && m)
	{
		getchar();
		int t=1,d=6,e=4,w=3,n=2,s=5, temp;
		char i[10];
		for (int j=0; j<m; j++)
		{
			scanf ("%s",&i);
			if (i[0]=='n')
			{
				temp=d;
				d=n;
				n=t;
				t=s;
				s=temp;
			}
			else if (i[0]=='s')
			{
				temp=d;
				d=s;
				s=t;
				t=n;
				n=temp;
			}
			else if (i[0]=='e')
			{
				temp=d;
				d=e;
				e=t;
				t=w;
				w=temp;
			}
			else
			{
				temp=d;
				d=w;
				w=t;
				t=e;
				e=temp;
			}
		}
		printf ("%d\n",t);
	}

	return 0;
}