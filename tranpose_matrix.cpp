#include <bits/stdc++.h>
using namespace std;

struct matrix
{
	int row;
	int coloum;
	int value;
};


int main()
{
	int n,k,j;
	cin >> n;
	matrix m[n];

	for (int i = 0; i < n; ++i)
	{
		cin >> m[i].row >> m[i].coloum >> m[i].value ;
	}

	int col[n];
	for (int i = 0; i < n; ++i)
	{
		col[i]=0;
	}

	int colo_max=0;

	for (int i = 0; i < n; ++i)
	{
		if (m[i].coloum > colo_max)
		{
			colo_max=m[i].coloum+1;
		}
		col[ (m[i].coloum) ]++;
	}

	int t=1,t1;

	for (int i = 0; i < colo_max; ++i)
	{	
		t1=col[i];
		col[i]=t;
		t=t+t1;
	}

	matrix m1[n+1];

	for (int i = 0; i < n; ++i)
	{
		m1[col[m[i].coloum]].row=m[i].coloum;

		m1[col[m[i].coloum]].coloum=m[i].row;

		m1[col[m[i].coloum]].value=m[i].value;

		col[m[i].coloum]++;


	}
printf("Transpose of martix is:\n");


	for (int i = 1; i <= n; ++i)
	{
		cout << m1[i].row << " " << m1[i].coloum << " " << m1[i].value << endl; 
	}
	printf("\n");

	return 0;
}

/*

8
0 0 15
0 3 22
0 5 -15
1 1 11
1 2 3
2 3 -6
4 0 91
5 2 28
*/
