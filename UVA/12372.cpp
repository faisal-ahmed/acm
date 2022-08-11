#include <stdio.h>

int main(){
    int tCase, i, a, b, c;
    scanf("%d", &tCase);
    for ( i = 1; i <= tCase; i++ ){
        scanf ("%d%d%d", &a, &b, &c);
        printf ("Case %d: %s\n", i, (a<21 && b<21 && c<21) ? "good" : "bad");
    }
    return 0;
}
