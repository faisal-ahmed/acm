#include <stdio.h>

struct Mtrx_node
{
	int r_c[3][3];
};

void Mtrx_multiply(struct Mtrx_node M[])
{
	int m=0;
	for (int i=0; i<3; i++)
	{
		for (int k=0; k<3; k++)
		{
			int value = 0;
			for (int j=0; j<3; j++)
				value += (M[0].r_c[m][j]*M[1].r_c[j][k]);
			M[2].r_c[i][k] = value;
		}
		m++;
	}
}
void input(struct Mtrx_node M[])
{
	for (int m=0; m<2; m++)
		for (int i=0; i<3; i++)
			for (int j=0; j<3; j++)
				scanf ("%d",&M[m].r_c[i][j]);
}
void Print(struct Mtrx_node M[])
{
	for (int k=0; k<3; k++)
	{
		for (int l=0; l<3; l++)
		{
			printf ("%d ",M[2].r_c[k][l]);
		}
		puts("");
	}
}

int main()
{
	printf ("This program calculates the multiplication results of two 3*3 Matrix.\nEnter the values of two 3*3 matrix below.\n");
	while (1)
	{
		struct Mtrx_node M[3];
		input(M);
		Mtrx_multiply(M);
		puts("");
		Print(M);
	}
	return 0;
}
