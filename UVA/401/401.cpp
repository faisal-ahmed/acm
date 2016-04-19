#include <stdio.h>
#include <string.h>

bool palin(char a[], int size)
{
	int last = size-1, i;
	for (i=0; i<(int)(size/2); i++)
	{
		if (a[i] != a[last])
			return false;
		last--;
	}
	return true;
}

bool mirror(char a[], int size)
{
	int last = size-1, limit, i;
	if (size%2!=0)
	{
		limit = size/2;
		if (!(a[limit] == 'A' || a[limit] == 'H' || a[limit] == 'I' || a[limit] == 'M' || a[limit] == 'O' || a[limit] == 'T' ||a[limit] == 'U' || a[limit] == 'V' ||a[limit] == 'W' || a[limit] == 'X' || a[limit] == 'Y' || a[limit] == '1' || a[limit] == '8'))
			return false;
	}
	for (i=0; i<size/2; i++)
	{
		if (a[i] == 'A')
		{
			if (a[last] != 'A')
				return false;
		}
		else if (a[i] == 'E')
		{
			if (a[last] != '3')
				return false;
		}
		else if (a[i] == 'H')
		{
			if (a[last] != 'H')
				return false;
		}
		else if (a[i] == 'I')
		{
			if (a[last] != 'I')
				return false;
		}
		else if (a[i] == 'J')
		{
			if (a[last] != 'L')
				return false;
		}
		else if (a[i] == 'L')
		{
			if (a[last] != 'J')
				return false;
		}
		else if (a[i] == 'M')
		{
			if (a[last] != 'M')
				return false;
		}
		else if (a[i] == 'O')
		{
			if (a[last] != 'O')
				return false;
		}
		else if (a[i] == 'S')
		{
			if (a[last] != '2')
				return false;
		}
		else if (a[i] == 'T')
		{
			if (a[last] != 'T')
				return false;
		}
		else if (a[i] == 'U')
		{
			if (a[last] != 'U')
				return false;
		}
		else if (a[i] == 'V')
		{
			if (a[last] != 'V')
				return false;
		}
		else if (a[i] == 'W')
		{
			if (a[last] != 'W')
				return false;
		}
		else if (a[i] == 'X')
		{
			if (a[last] != 'X')
				return false;
		}
		else if (a[i] == 'Y')
		{
			if (a[last] != 'Y')
				return false;
		}
		else if (a[i] == 'Z')
		{
			if (a[last] != '5')
				return false;
		}
		else if (a[i] == '1')
		{
			if (a[last] != '1')
				return false;
		}
		else if (a[i] == '2')
		{
			if (a[last] != 'S')
				return false;
		}
		else if (a[i] == '3')
		{
			if (a[last] != 'E')
				return false;
		}
		else if (a[i] == '5')
		{
			if (a[last] != 'Z')
				return false;
		}
		else if (a[i] == '8')
		{
			if (a[last] != '8')
				return false;
		}
		else
			return false;
		last--;
	}
	return true;
}

int main()
{
//	freopen ("in.txt","rb",stdin);
//	freopen ("out.txt","w",stdout);

	char input[22];
	int i=0;

	while (gets (input))
	{
		int len = strlen(input);
		bool p = palin(input,len), m = mirror(input,len);
		if (p==0 && m==0)
			printf ("%s -- is not a palindrome.\n",input);
		else if (p==0 && m==1)
			printf ("%s -- is a mirrored string.\n",input);
		else if (p==1 && m==0)
			printf ("%s -- is a regular palindrome.\n",input);
		else
			printf ("%s -- is a mirrored palindrome.\n",input);
		puts("");
	}

	return 0;
}