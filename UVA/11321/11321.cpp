#include<stdio.h>
#include<algorithm>

using namespace std;

#define ii long long int

ii M, input[110000], loopI, N;

bool cmp(ii a, ii b){
    if ( a % M == b % M ){
        if ( !(a % 2) && !(b % 2) ) return (a < b);
        else if ( a % 2 && b % 2  ) return (a > b);
        else return ( a % 2 ) ? true : false;
    }

    return ( a % M < b % M );
}

int main(){
    while ( scanf("%lld%lld", &N, &M) == 2 ){

        if(!N && !M) break;

        for (loopI = 0; loopI < N; loopI++) scanf("%lld", &input[loopI]);

        sort(input, input + N, cmp);

        printf("%lld %lld\n", N, M);
        for (loopI = 0; loopI < N; loopI++) printf("%lld\n", input[loopI]);
    }
    puts("0 0");

    return 0;
}
