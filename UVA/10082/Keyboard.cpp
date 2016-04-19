#include<stdio.h>
#include<string.h>
//10082
char one[49] = { "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./" };

int main()
{
	char input[1000];
	
	gets (input)
	
	for (int a=0; a < strlen(input); a++)
	{
			for (int b=0; b<=47; b++)
			{
				if (input[a]==' ')
				{	
					printf (" ");
					break;
				}
				if (input[a]==one[b])
				{
					printf ("%c",one[b-1]);
					break;
				}
			}
	}
	puts("");

	return 0;
}
