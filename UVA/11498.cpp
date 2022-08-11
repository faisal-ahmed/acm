#include <stdio.h>

int main(){
    int query;

    while (scanf("%d", &query) && query != 0){
        int x, y, n, m;
        scanf ("%d%d", &n, &m);
        while (query--){
            scanf ("%d%d", &x, &y);
            if ( x > n && y > m ) puts("NE");
            else if ( x < n && y > m ) puts("NO");
            else if ( x < n && y < m ) puts("SO");
            else if ( x > n && y < m ) puts("SE");
            else puts("divisa");
        }
    }

    return 0;
}
