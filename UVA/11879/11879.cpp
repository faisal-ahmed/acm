#include <stdio.h>
#include <string.h>
#include <string>

using namespace std;

int main()
{
    char input[200];

    while (gets(input) && input[0] != '0')
    {
        int temp = 0, i;
        for (i=0; input[i] != NULL; i++)
        {
            temp *= 10;
            temp += (input[i]-'0');
            temp %= 17;
        }
        if (temp%17 == 0) puts("1");
        else puts("0");
    }

    return 0;
}
