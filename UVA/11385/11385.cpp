#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>>

int main(){
    int tCase, loopI;
    long long int fib[50];
    fib[0] = fib[1] = 1;
    for (loopI = 2; loopI < 50; loopI++) fib[loopI] = fib[loopI-1] + fib[loopI-2];

    scanf("%d", &tCase);

    while(tCase--){
        int fibCount, charPosInResultStr[60], loopJ, endingFib = 0;
        memset(charPosInResultStr, -1, sizeof(charPosInResultStr));
        scanf("%d", &fibCount);
        for(loopJ = 0; loopJ < fibCount; loopJ++){
            int currentFib;
            scanf("%d", &currentFib);
            for (loopI = 1; loopI < 47; loopI++){
                if (currentFib == fib[loopI]) {
                    charPosInResultStr[loopJ] = loopI;
                    if (loopI > endingFib) endingFib = loopI;
                    break;
                }
            }
        }
        char result[50], inputStr[105];
        for (loopI = 0; loopI < 50; loopI++) result[loopI] = ' ';
        getchar();
        gets(inputStr);
        loopJ = loopI = 0;
        for(loopI = 0; loopI < fibCount; loopI++){
            while (!isupper(inputStr[loopJ++]));
            result[charPosInResultStr[loopI]] = inputStr[loopJ-1];
        }
        for(loopJ = 1; loopJ <= endingFib; loopJ++) printf("%c", result[loopJ]);
        printf("\n");
    }

    return 0;
}
