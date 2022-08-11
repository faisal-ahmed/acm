#include <stdio.h>

int diff(int a, int b) { return (a >= b) ? (a - b) : (40 - b + a); }

int main(){
    int a, b, c, d;

    while ( scanf("%d%d%d%d", &a, &b, &c, &d) == 4 &&
           (a !=0 || b != 0 || c != 0 || d != 0) ) {

        int result = diff(a, b) + diff (c, b) + diff(c, d);
        printf ("%d\n", (result * 9 + 1080) );
    }

    return 0;
}
