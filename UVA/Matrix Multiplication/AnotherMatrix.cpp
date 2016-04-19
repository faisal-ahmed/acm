#include <stdio.h>
#include <string.h>
#include <ctype.h>

struct Mat_node
{
	int r_c[10][10];
};

struct rows_column
{
	int r_c_limit[2];
};

void Mat_multip(struct Mat_node M[], struct rows_column c[])
{
	int m=0;
	for (int i=0; i<c[0].r_c_limit[0]; i++)
	{
		for (int k=0; k<c[1].r_c_limit[1]; k++)
		{
			int value = 0;
			for (int j=0; j<c[0].r_c_limit[1]; j++)
				value += (M[0].r_c[m][j]*M[1].r_c[j][k]);
			M[2].r_c[i][k] = value;
		}
		m++;
	}
}
void input(struct Mat_node M[], struct rows_column c[])
{
	bool flag1 = false, flag2 = true;
	for (int m=0; m<2; m++)
	{
		for (int i=0; i<10; i++)
		{
			if (flag1)
				break;
			char test[50];
			gets(test);
			if (test[0]!='*')
			{
				c[m].r_c_limit[1] = 0;
				int j=0, value = 0, h=strlen(test);
				flag2 = true;
				for (int k=0; k<=h; k++)
				{
					if (test[k] == ' ' || test[k] == NULL)
					{
						if (flag2)
						{
							M[m].r_c[i][j] = value;
							c[m].r_c_limit[1]++;
							j++;
							flag2 = false;
							value = 0;
						}
					}
					else
					{
						flag2 = true;
						value *= 10;
						value += (test[k] - '0');
					}
				}
				c[m].r_c_limit[0]++;
			}
			else
				flag1 = true;
		}
		flag1 = false;
	}
}
void Print(struct Mat_node M[], struct rows_column c[])
{
	for (int k=0; k<c[0].r_c_limit[0]; k++)
	{
		for (int l=0; l<c[1].r_c_limit[1]; l++)
		{
			printf ("%d ",M[2].r_c[k][l]);
		}
		puts("");
	}
}

int main()
{
	printf ("This program calculates the valid multiplication result of two Matrixes.\nEnter the values of two matrixes below. After entering the values of a matrix\ngive a input of a star(*).\n");
	while (1)
	{
		struct Mat_node M[3];
		struct rows_column cal[2];
		cal[0].r_c_limit[0] = cal[0].r_c_limit[1] = cal[1].r_c_limit[0] = cal[1].r_c_limit[1] = 0;
		input(M,cal);
		if (cal[0].r_c_limit[1] == cal[1].r_c_limit[0])
		{
			Mat_multip(M,cal);
			Print(M,cal);
			puts("");
		}
		else
			printf ("Impossible\n");
	}

	return 0;
}