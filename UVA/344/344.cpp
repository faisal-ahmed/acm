#include <stdio.h>
int num, i[103], v[103], x[103], l[103], c[103], j;

int main()
{
	for (j=1;j<102;j++)
	{
		if (j%5==1 || j%5==4)
			i[j] = 1;
		else if (j%5==2)
			i[j] = 2;
		else if (j%5==3)
			i[j] = 3;
		if (j%10>=4 && j%10<=8)
			v[j]=1;
		if (j>=40 && j<=89)
			l[j]=1;
		if (j>=90 && j<=100)
			c[j]=1;
		if (j>8 && j<=18)
			x[j]=1;
		else if (j>18 && j<=28)
			x[j]=2;
		else if (j>28 && j<=38)
			x[j]=3;
		else if (j>38 && j<=48)
			x[j]=1;
		else if (j>58 && j<=68)
			x[j]=1;
		else if (j>68 && j<=78)
			x[j]=2;
		else if (j>78 && j<=88)
			x[j]=3;
		else if (j>88 && j<=98)
			x[j]=1;
		if (j>=90)
			c[j]=1;
	}

	x[39] = x[89] = 4;
	x[49] = x[99] = 2;

	while (scanf ("%d",&num)==1 && num)
	{
		int r,  i_res=0, v_res=0, x_res=0, l_res=0, c_res=0;
		for (r=1;r<=num;r++)
		{
			i_res += i[r];
			v_res += v[r];
			x_res += x[r];
			l_res += l[r];
			c_res += c[r];
		}
		printf ("%d: %d i, %d v, %d x, %d l, %d c\n",num,i_res,v_res,x_res,l_res,c_res);
	}

	return 0;
}