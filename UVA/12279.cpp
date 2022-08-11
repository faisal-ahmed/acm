#include <stdio.h>

int main(){
    int tCase, printKase = 1;

    while (scanf("%d", &tCase) && tCase != 0){
        int a, treat = 0, notTreat = 0, i;
        for (i = 0; i < tCase; i++) {
            scanf ("%d", &a);
            (a==0) ? treat++ : notTreat++;
        }
        printf ("Case %d: %d\n", printKase++, (notTreat-treat));
    }

    return 0;
}
