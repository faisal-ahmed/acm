#include <stdio.h>
#include <string.h>

int main(){
    int tCase;
    scanf ("%d", &tCase);
    while (tCase--){
        int one = 0;
        char word[10];
        scanf ("%s", word);
        if (strlen(word) == 5) puts("3");
        else {
            if (word[0] == 'o') one++;
            if (word[1] == 'n') one++;
            if (word[2] == 'e') one++;
            if (one >= 2) puts("1");
            else puts("2");
        }
    }

    return 0;
}
