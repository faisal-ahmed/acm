#include <stdio.h>
#include <ctype.h>
int prime[1500];

void primegen()
{
	int n=1500;
	for (int i=4; i<n; i+=2)
		prime[i] = 1;
	for (int j=3; j*j<n; j+=2)
		for (int k=j*j; k<n; k+=j)
			prime[k] = 1;
}

int main()
{
	primegen();
	char input[25];
	while (gets(input))
	{
		int i, res = 0;
		for (i=0; input[i]!='\0'; i++)
		{
			if (islower(input[i]))
				res += (input[i]-'a'+1);
			else
				res += (input[i]-'A'+27);
		}
		if (prime[res]==0)
			printf ("It is a prime word.\n");
		else
			printf ("It is not a prime word.\n");
	}
	return 0;
}