#include <stdio.h>

int main()
{
	char input1[5000],input2, input3[5000];
	while (scanf ("%s",input1)==1)
	{
		getchar();
		scanf ("%c%s",&input2,input3);
		int i;
		long long int value1=0, value2=0, value3=0;
		for (i=0; input1[i] != NULL && i<10; i++)
		{
			value1*=10;
			value1+=(input1[i]-'0');
		}
		for (i=0; input3[i] != NULL && i<10; i++)
		{
			value2*=10;
			value2+=(input3[i]-'0');
		}
		if(value1<2147483648 && value2<2147483648)
		{
			if (input2=='+')
				value3=value1+value2;
			else
				value3=value1*value2;
		}
		else
			value3 = 2147483648;
		printf ("%s %c %s\n",input1,input2,input3);
		if (value1>2147483647)
			printf ("first number too big\n");
		if (value2>2147483647)
			printf ("second number too big\n");
		if (value3>2147483647 && value1 != 0 && value2 != 0)
			printf ("result too big\n");
	}

	return 0;
}