#include<stdio.h>
long long p[100002],i,j,k,r,h[1299719];
int main()
{
p[0]=2;
for(i=3;k<100001;i+=2)
if(!h[i]){p[++k]=i;
for(j=i*i;j<1299719;j+=2*i)
h[j]=1;
}
while(scanf("%d",&r)==1)printf("%d\n",p[r-1]);
return 0;
}