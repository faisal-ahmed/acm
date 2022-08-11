#include <stdio.h>
#include <math.h>

int main(){
    int tCase, result = 0, donate;

    scanf("%d", &tCase);

    while (tCase--){
        char command[10];
        scanf("%s", command);
        if (command[0] == 'r'){
            printf ("%d\n", result);
        } else {
            scanf ("%d", &donate);
            result += donate;
        }
    }

    return 0;
}


