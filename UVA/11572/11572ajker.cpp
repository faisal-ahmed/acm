#include <stdio.h>
#include <map>
using namespace std;

int main()
{
	int kase;
	scanf ("%d",&kase);

	while (kase--)
	{
		map<int,int>A;
		int limit, max=0, finalCount=0, hold, i, unic = 0, count1=0, count2=0;
		scanf ("%d",&limit);

		for (i=1; i<=limit; i++)
		{
			scanf ("%d",&hold);
			if (!(A.find(hold) != A.end()))
			{
				A[hold] = i;
				finalCount++;
				if (max<finalCount)
					max=finalCount;
			}
			else
			{
				count1 = i-A[hold];
				count2 = i-unic;
				if (count1<count2)
					finalCount=count1;
				else
					finalCount = count2;
				if (unic<A[hold])
					unic = A[hold];
				A[hold] = i;
				if (max<finalCount)
					max=finalCount;
			}
		}
		printf ("%d\n",max);
	}

	return 0;
}