#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

typedef unsigned long long LL;

struct data
{
    LL in;

    data(){}
    data(LL a) { in = a; }

    bool operator < (data X) const
    {
        return in > X.in;
    }
};

int main()
{
    int n,i;

    while (scanf ("%d",&n)==1 && n)
    {
        LL ans = 0, hold, test;
        data curr;
        priority_queue <data> input;

        for (i=0; i<n; i++)
        {
            scanf ("%llu",&test);
            input.push(data(test));
        }

        while (input.size() != 1)
        {
            curr = input.top();
            input.pop();
            hold = curr.in;
            curr = input.top();
            input.pop();
            hold += curr.in;
            ans += hold;
            input.push(data(hold));
        }
        printf ("%llu\n",ans);
    }

    return 0;
}
