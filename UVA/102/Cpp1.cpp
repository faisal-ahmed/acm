#include<stdio.h>
int bin[3][3],a,b,c,d,e,f,best;
								// 0 1 2
								// B G C

int main()
{
	while (scanf("%d%d%d%d%d%d%d%d%d",&bin[0][0],&bin[0][1],&bin[0][2],&bin[1][0],&bin[1][1],&bin[1][2],&bin[2][0],&bin[2][1],&bin[2][2])==9)
	{
		a = bin[1][0]+bin[2][0] + bin[0][2]+bin[2][2] + bin[0][1]+bin[1][1]; // BCG
		b = bin[1][0]+bin[2][0] + bin[0][1]+bin[2][1] + bin[0][2]+bin[1][2]; // BGC
		c = bin[1][2]+bin[2][2] + bin[0][0]+bin[2][0] + bin[0][1]+bin[1][1]; // CBG
		d = bin[1][2]+bin[2][2] + bin[0][1]+bin[2][1] + bin[0][0]+bin[1][0]; // CGB
		e = bin[1][1]+bin[2][1] + bin[0][0]+bin[2][0] + bin[0][2]+bin[1][2]; // GBC
		f = bin[1][1]+bin[2][1] + bin[0][2]+bin[2][2] + bin[0][0]+bin[1][0]; // GCB

		best=a;

		if (b<best)
			best=b;

		if (c<best)
			best=c;

		if (d<best)
			best=d;

		if (e<best)
			best=e;

		if (f<best)
			best=f;

		if (best==a)
			printf ("BCG %d\n",a);
		else if (best==b)
			printf ("BGC %d\n",b);
		else if (best==c)
			printf ("CBG %d\n",c);
		else if (best==d)
			printf ("CGB %d\n",d);
		else if (best==e)
			printf ("GBC %d\n",e);
		else if (best==f)
			printf ("GCB %d\n",f);
	}

	return 0;
}
