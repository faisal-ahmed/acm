#include <stdio.h>
#include <string.h>
#include <sstream>
#include <string>
using namespace std;

string in[2];

int mod(int a)
{
    int i, temp = 0;
    for (i=0; i<in[1].size(); i++)
    {
        temp *= 10;
        temp += (in[1][i]-'0');
        temp %= a;
    }
    return temp%a;
}

int main()
{
    int i, hold[10][4] = {0,0,0,0,
    1,1,1,1,
    6,2,4,8,
    1,3,9,7,
    6,4,6,4,
    5,5,5,5,
    6,6,6,6,
    1,7,9,3,
    6,8,4,2,
    1,9,1,9};

    char input[1000];
    while (gets(input))
    {
        stringstream ss(input);
        ss>>in[0];
        ss>>in[1];
        if (in[0][0] == '0' && in[1][0] == '0') break;
        int a = in[0][in[0].size()-1]-'0';

        if (in[1][0]=='0' && a!=0)
        {
            printf ("1\n");
        }
        else if (a == 0 || a == 1 || a == 5 || a == 6)
        {
            printf ("%d\n",a);
        }
        else if (a==2 || a==3 || a==7 || a==8)
        {
            printf ("%d\n",hold[a][mod(4)]);
        }
        else
        {
            printf ("%d\n",hold[a][mod(2)]);
        }
    }

    return 0;
}
