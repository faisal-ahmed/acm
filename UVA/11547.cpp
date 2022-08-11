#include <stdio.h>
#include <math.h>

int main(){
    int tCase, number;

    scanf("%d", &tCase);

    while (tCase--){
        scanf("%d", &number);
        printf ("%d\n", abs(((((number * 567 / 9 + 7492) * 235 / 47) - 498 ) / 10) % 10) );
    }

    return 0;
}
