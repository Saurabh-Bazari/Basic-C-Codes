#include <bits/stdc++.h>
using namespace std;

void maxheapify(long long int data[],int n1,int x){

	int l=2*x+1;
	int r=2*x+2;
	int p=x;

	if (l <= n1 && data[l] < data[p])
	{
		p=l;		
	}
	if (r <= n1 && data[r] < data[p])
	{
		p=r;
	}

	if (p!=x)
	{
		swap(data[p],data[x]);
		maxheapify(data,n1,p);
	}

	return;
}

long long int extract(long long int data[],int &n1){

	long long int ans=data[0];

	n1--;

	data[0]=data[n1];

	maxheapify(data,n1-1,0);

	return ans;
}


void insert(long long int data[],int &n1){

	long long int t;
	cin >> t;

	data[n1++]=t;

	int p,s;
	s=n1-1;
	p=(s-1)/2;

	while( p >= 0 && data[p] > data[s] ){

		swap(data[s],data[p]);
		s=p;
		p=(p-1)/2;
	}

	return;
}

void call(){

	int n;
	cin >> n;

	long long int data[n];

	int n1=0;

	for (int i = 0; i < n; ++i)
		insert(data,n1);

	long long int k=extract(data,n1),k1,diff,minn=INT_MAX;

	for (int i = 0; i < n-1 ; ++i)
	{
		k1=extract(data,n1);

		diff=k1-k;
		k=k1;

		if ( diff < minn )
			minn=diff;
	}

	cout << minn << endl;

	
	return;
}

int main(){

	int t;
	cin >> t;

	for (int i = 0; i < t; ++i)
		call();

	return 0;
}