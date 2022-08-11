#include <stdio.h>
#include <string.h>

int main(){
    int N;

    while (scanf("%d", &N) == 1 && N != 0){
        int rows[110], column[110], i, j, iteratorI, tempIn, oddRowsCount = 0, oddColumnCount = 0;

        memset(rows, 0, N * sizeof(rows[0]));
        memset(column, 0, N * sizeof(column[0]));

        for (i = 0; i < N; i++){
            for (j = 0; j < N; j++){
                scanf ("%d", &tempIn);
                rows[i] += tempIn;
                column[j] += tempIn;
            }
        }

        for (iteratorI = 0; iteratorI < N; iteratorI++){
            if (rows[iteratorI] % 2 == 1) {
                oddRowsCount++;
                i = iteratorI + 1;
            }
            if (column[iteratorI] % 2 == 1) {
                oddColumnCount++;
                j = iteratorI + 1;
            }
        }

        if (oddRowsCount == 0 && oddColumnCount == 0){
            puts("OK");
        } else if (oddRowsCount == 1 && oddColumnCount == 1){
            printf ("Change bit (%d,%d)\n", i, j);
        } else {
            puts("Corrupt");
        }
    }

    return 0;
}
