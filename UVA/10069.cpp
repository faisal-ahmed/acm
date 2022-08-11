#include <stdio.h>
#include <string.h>

char X[10010], Z[105];
int dp[10010][105], X_len, Z_len;

int f(int i, int j){ // i is the position of X, and j is the position of Z
    if (dp[i][j] != -1) return dp[i][j];
    if (j >= Z_len) return 1;

    int loopIterator, endPosition = X_len - (Z_len - j) + 1, subsetFound = 0;
    for (loopIterator = i; loopIterator < endPosition; loopIterator++){
        if (X[loopIterator] == Z[j]) subsetFound += f(loopIterator+1, j+1);
    }

    return (dp[i][j] = subsetFound);
}

int main(){

    int tCase;
    scanf ("%d", &tCase);

    while (tCase--){
        memset(dp, -1, sizeof(dp));

        scanf ("%s%s", X, Z);

        X_len = strlen(X);
        Z_len = strlen(Z);

        if (Z_len == X_len) {
            if (strcmp(X,Z) == 0) puts("1");
            else puts ("0");
        } else if (Z_len > X_len) {
            puts ("0");
        } else {
            printf ("%d\n", f(0, 0));
        }
    }

    return 0;
}
