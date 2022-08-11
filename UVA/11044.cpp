#include <stdio.h>
#include <math.h>

int main(){
    int tCase, a, b;

    scanf("%d", &tCase);

    while (tCase--){
        scanf("%d%d", &a, &b);
        printf ("%d\n", int(a/3) * int(b/3) );
    }

    return 0;
}

