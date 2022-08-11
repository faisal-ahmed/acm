#include <stdio.h>
#include <algorithm>
using namespace std;

int main(){
    int tCase, N, printKase;

    scanf ("%d", &tCase);
    for (printKase = 1; printKase <= tCase; printKase++){
        scanf("%d", &N);
        int i, creatures[10010];
        for (i = 0; i < N; i++) scanf ("%d", &creatures[i]);
        sort(creatures, creatures + N);
        printf("Case %d: %d\n", printKase, creatures[N-1]);
    }

    return 0;
}
