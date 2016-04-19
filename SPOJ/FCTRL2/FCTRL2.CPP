#include <stdio.h>
#include <string.h>
#include <string>
using namespace std;

#define FOR(i,a,b) for (i=a; i<b; i++)

string a[102];
char hold[10000];

void f(int n)
{
	int i, temp = 0, j;
	for (i=0; hold[i] != NULL; i++)
	{
		temp += ((hold[i]-'0')*n);
		hold[i] = (temp%10+'0');
		temp /= 10;
	}
	while (temp)
	{
		hold[i] = (temp%10+'0');
		temp /= 10; i++;
	}
	hold[i] = NULL;
	for (j=i-1; j>=0; j--) a[n] += hold[j];
}

int main()
{
	int kase, input, i;
	hold[0] = '1';
	hold[1] = NULL;
	FOR(i,1,101) f(i);

	scanf ("%d",&kase);

	while (kase--)
	{
		scanf ("%d",&input);
		printf ("%s\n",a[input].c_str());
	}

	return 0;
}