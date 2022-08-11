#include <stdio.h>

int main(){
    for (int printCase = 1; true; printCase++){
        char hajjTitle[100];
        scanf ("%s", hajjTitle);
        if (hajjTitle[0] == '*') break;
        else if (hajjTitle[0] == 'H') printf ("Case %d: Hajj-e-Akbar\n", printCase);
        else printf ("Case %d: Hajj-e-Asghar\n", printCase);
    }

    return 0;
}
