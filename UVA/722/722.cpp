#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>
using namespace std;

char grid[102][102];
int Rsize, Csize, visited[102][102];

int f(int a, int b)
{
	if (a<0 || b<0) return 0;
	if (b==Csize || a==Rsize) return 0;
	if (grid[a][b] != '0') return 0;
	if (visited[a][b]) return 0;
	visited[a][b] = 1;
	int count = 1;
	count += f(a-1,b);
	count += f(a,b-1);
	count += f(a+1,b);
	count += f(a,b+1);
	return count;
}

int main()
{
	int kase, flag = 0;
	scanf ("%d",&kase);

	while (kase--)
	{
		memset(visited,0,sizeof (visited));
		if (flag) puts("");
		flag++;
		int a, b, i = 0;
		scanf ("%d%d",&a,&b);
		getchar();
		while (gets(grid[i]) && grid[i][0] != NULL) i++;
		Csize = strlen(grid[0]);
		Rsize = i;
		printf ("%d\n",f(a-1,b-1));
	}

	return 0;
}