#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
using namespace std;

void fac(int n, int test[], int& index)
{
    index = 0;
    int i;
    for (i=2; i*i<=n; i++)
    {
        int count = 0;
        while (n%i==0)
        {
            n/=i;
            count++;
        }
        if (count > 0) test[index++] = i;
    }
    if (n>1) test[index++] = n;
}

int main()
{
	int kase; scanf ("%d",&kase);

	while (kase--)
	{
		int a, c, b, i;
		scanf ("%d%d",&a,&c);

		if (c%a==0)
		{
		    b = c/a;
		    int fact[150], index = 0;
		    fact[0] = 1;
		    fact[0] *= (1<<30);
		    fac(b,fact,index);

		    for (i=0; i<index; i++)
		    {
		        int count = 0;
		        while (a%fact[i] == 0)
		        {
		            a /= fact[i];
		            count++;
		        }
		        if (count > 0) b *= (pow(fact[i],count));
		    }

		    printf ("%d\n",b);
		}
		else puts("NO SOLUTION");
	}

	return 0;
}
