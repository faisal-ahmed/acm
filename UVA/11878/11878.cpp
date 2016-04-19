#include <stdio.h>
#include <string.h>

int main()
{
    char input[1000];
    int correct = 0;

    while (gets(input))
    {
        char chinho;
        int size = strlen(input), i, a, b, c;
        if (input[size-1] == '?') continue;
        sscanf (input,"%d%c%d%*c%d",&a,&chinho,&b,&c);
        if (chinho == '-' && a-b==c) correct++;
        else if (chinho=='+' && a+b==c) correct++;
    }
    printf ("%d\n",correct);

    return 0;
}
