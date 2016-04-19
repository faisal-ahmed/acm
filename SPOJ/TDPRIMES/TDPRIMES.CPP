#include <stdio.h>

char test[6250001]; ///bit 50000008

#define chkB(a,n) (a[n>>3]&(1<<(n&7)))
#define setB(a,n) (a[n>>3]|=(1<<(n&7)))

int main()
{
//	freopen("out.txt","w",stdout);
	printf ("#include<stdio.h>\nint main()\n{\nprintf (\"");
	int i = 2, j, bit = 3, value = 7, count = 2;
	printf ("2\n");

	for (i = 4; i<50000008; i+=3) setB(test,i);
	for (i = 12; i<50000008; i+=5) setB(test,i);
	for (i = 2; ((value*value)>>1) < 50000008; i++)
	{
		bit = (value>>1);
		if (!chkB(test,bit)) for (j=((value*value)>>1); j<50000008; j+=value) setB(test,j);
		value += 4;
		bit = (value>>1);
		if (!chkB(test,bit)) for (j=((value*value)>>1); j<50000008; j+=value) setB(test,j);
		value = 6*i+1;
	}

	value = 7;
	for (i = 2; value<100000000; i++)
	{
		bit = (value>>1);
		if (!chkB(test,bit)) count++;
		if (count==100) { printf ("%d\\n",value); count = 0; }
		value += 4;
		bit = (value>>1);
		if (!chkB(test,bit)) count++;
		if (count==100) { printf ("%d\\n",value); count = 0; }
		value = 6*i+1;
	}
	printf ("\")\;\nreturn 0\;}");

	return 0;
}

/* 6k+1 or 6k+5 er khetre k is atmost 14338020;  100000000  */
