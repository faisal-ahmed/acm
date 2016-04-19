#include <stdio.h>
#include <ctype.h>
#include <stack>
using namespace std;

int main()
{
	stack<int>list;
	char input_test[200500], input[200500];
	gets(input_test);

	int start = 0, i, j, flag = 0, k, m=0;

	for (k=0; input_test[k] != NULL; k++)
	{
		if (isalpha(input_test[k]))
		{
			input[m] = input_test[k];
			m++;
		}
	}
	list.push(0);
	for (i=1; i<m; ++i)
	{
		if (input[start] == input[i])
		{
			input[start] = input[i] = NULL;
			if (start-1 >= 0)
			{
				if (!list.empty())
				{
					start = list.top();
					list.pop();
					flag = 1;
				}
				else
					start = i;
			}
			else
				start = i;
		}
		else if (flag)
		{
			list.push(start);
			start = i;
			flag = 0;
		}
		else
		{
			list.push(start);
			start++;
		}
	}

	for (j=0; j<m; j++)
		if (input[j] != NULL)
			printf ("%c",input[j]);
	puts("");

	return 0;
}