#include <bits/stdc++.h>
using namespace std;

int h=INT_MAX;

int main()
{
	int n,j;
	cin >> n;
	int data[n][100],cnt[n];

	for (int i = 0; i < n; ++i)
	{
		cnt[i]=0;
	}

	for (int i = 0; i < n; ++i)
	{
		for ( j = 0; j < 100; ++j)
		{
			cin >> data[i][j];
			if (data[i][j]==-1)
			{
				data[i][j]=h;

				break;
			}
		}
	}

	int t=2*n,y=0;
	int ary[t];

while(y!=h){

	t=2*n;
	j=0;
	for (int i = (t/2); i < t ; ++i )
	{
		ary[i]=data[j][cnt[j]];
		j++;
	}

	while(t!=1){
		for (int i = (t/2); i < t-1	; i+=2)
		{
			if (ary[i]>ary[i+1])
			{
				ary[i/2]=ary[i+1];
			}
			else{
				ary[i/2]=ary[i];
			}
		}
		t=t/2;
	}

	y=ary[1];

	if (y!=h){
		printf("%d ",y);
	}
	else{
		break;
	}

	for (int i = 0; i < n; ++i)
	{
		if (y==data[i][cnt[i]])
		{
			cnt[i]++;
		}
	}
}

	return 0;
}

/* 
4 
1 5 9 -1 
2 4 10 -1 
3 7 -1 
6 8 11 -1 
*/