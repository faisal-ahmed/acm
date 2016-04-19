#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>
using namespace std;

struct bigSquare
{
	vector<string> a;
};

struct smallSquare
{
	vector<string> a;
};

struct smallSquare90
{
	vector<string> a;
};

struct smallSquare180
{
	vector<string> a;
};

struct smallSquare270
{
	vector<string> a;
};

void rotate(vector<string>& a, vector<string>& ret)
{
	for (int i=0; i<a.size(); i++) // col
	{
		string b;
		for (int j=a.size()-1; j>=0; j--) // row
		{
			b += a[j][i];
		}
		ret.push_back(b);
	}
}

bool squreCheck(vector<string>& a, vector<string>& b)
{
	for (int i=0; i<a.size(); i++)
		if (a[i] != b[i]) return false;
	return true;
}

string substr(string a, int pos, int limit)
{
	string ret;
	for (int i=0; i<limit; i++)
		ret += a[pos+i];
	return ret;
}

int howMany( vector<string>& a, vector<string>& b)
{
	int ret = 0;
	for (int row=0; row<=a.size()-b.size(); row++)
	{
		for (int col=0; col<=a.size()-b.size(); col++)
		{
			vector<string> check;
			for (int takeRow = row; takeRow< row+b.size(); takeRow++)
			{
				string f = substr(a[takeRow],col,b.size());
				check.push_back(f);
			}
			if (squreCheck(check,b)) ret++;
		}
	}
	return ret;
}

int main()
{
	int N, n;

	while (scanf ("%d%d",&N,&n)==2 && (N||n))
	{
		getchar();
		char in[100000];
		int i, j;
		string p;
		vector<string> rot;
		bigSquare big; smallSquare small; smallSquare90 small90; smallSquare180 small180; smallSquare270 small270;

		for (i=0; i<N; i++)
		{
			gets(in);
			p = in;
			big.a.push_back(p);
		}
		for (i=0; i<n; i++)
		{
			gets(in);
			p = in;
			small.a.push_back(p);
		}
		rotate(small.a, small90.a);
		rotate(small90.a, small180.a);
		rotate(small180.a, small270.a);
		int a, b, c, d;

		a = howMany(big.a, small.a);
		b = howMany(big.a, small90.a);
		c = howMany(big.a, small180.a);
		d = howMany(big.a, small270.a);

		printf ("%d %d %d %d\n",a ,b, c, d);
	}
	
	return 0;
}