#include<stdio.h>

char sakni[1000005];

void isPrime(int in)
{
    int i,j;
    sakni[0] = sakni[1] = 1;
    for(i=2; i*i<in; i++)
    {
        if(sakni[i] == 0)
        {
            for(j=i*i; j<=in; j+=i)
                sakni[j] = 1;
        }    
    }    
} 

int main()
{
    int n,j;
    isPrime(1000000);
    while(scanf("%d",&n) == 1)
    {
        if(n==0) 
            break;
        for(j=2;j<=n/2;j++)
        {
            if( (sakni[j]==0) && (sakni[i-j]==0) )
                break;
        }        
        if(j>(n/2))
            printf("%d:\nNO WAY!\n",n);
        else
            printf("%d:\n%d+%d\n",n,j,n-j);
    }
    return 0;
}
