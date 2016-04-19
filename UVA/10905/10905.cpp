#include <stdio.h>
#include <string.h>
#include <string>
#include <algorithm>
using namespace std;

bool f(string a, string b)
{
    string c = a+b, d = b+a;
    return c>d;
}

struct info
{
    string p;

    bool operator < (info X) const
    {
        if (p.size() == X.p.size()) return p>X.p;
        else return f(p,X.p);
    }
};

int main()
{
    int n;

    while (scanf ("%d",&n)==1 && n)
    {
        int i;
        char temp[100000];
        info input[55];
        for (i=0; i<n; i++)
        {
            scanf ("%s",temp);
            input[i].p = temp;
        }
        string res;

        sort(input,input+n);

        for (i=0; i<n; i++)
        {
            res += input[i].p;
        }

        printf ("%s\n",res.c_str());
    }

    return 0;
}
