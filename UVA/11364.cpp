#include <stdio.h>
#include <algorithm>
using namespace std;

int main(){

    int tCase, streetPoints[105], numberOfStreetPoints, i;
    scanf("%d", &tCase);

    while (tCase--){
        scanf("%d", &numberOfStreetPoints);

        for (i = 0; i < numberOfStreetPoints; i++){
            scanf("%d", &streetPoints[i]);
        }

        sort(streetPoints, streetPoints + numberOfStreetPoints);

        printf ("%d\n", (streetPoints[numberOfStreetPoints - 1] - streetPoints[0]) * 2 );
    }

    return 0;
}
