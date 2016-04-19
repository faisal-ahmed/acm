#include <stdio.h>
#include <string.h>
#include <vector>

using namespace std;

bool prime[20000100];

struct state
{
    int a, b;
};

int main()
{
    int n, i, j, k = 0;
    state p[100002];

    for (i=3; i*i<20000010; i+=2)
    {
        if (!prime[i]) for (j=i*i; j<20000010; j+=(2*i)) prime[j] = 1;
    }

//    puts("Yes");

    for (i=3; (i+2)<20000000; i+=2)
    {
        if (k == 100000) break;
        if (!prime[i] && !prime[i+2])
        {
            p[k].a = i;
            p[k].b = i+2;
            k++;
        }
    }

//    puts("2");

    while (scanf ("%d",&n)==1)
    {
        printf ("(%d, %d)\n",p[n-1].a, p[n-1].b);
    }

    return 0;
}
