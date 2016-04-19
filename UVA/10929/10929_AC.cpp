#include <stdio.h>
#include <string.h>
#include <string>
#include <algorithm>
#include <sstream>
using namespace std;

int main()
{
    char input[1100];

    while (gets(input))
    {
        stringstream ss(input);
        string hold;
        ss>>hold;
        int temp = 0, i=0, size = hold.size(), flag = 0;
        while (i<size)
        {
            if (hold[i]-'0') flag = 1;
            temp *= 10;
            temp += (hold[i]-'0');
            temp = temp%11;
            i++;
        }
        if (!flag) break;
        if (!temp) printf ("%s is a multiple of 11.\n",input);
        else printf ("%s is not a multiple of 11.\n",input);
    }

    return 0;
}
