#include <bits/stdc++.h>
using namespace std;

void call1(long int a[],long int l,long int r){

	if ((r-l) < 2 )
	{
		cout << "0" << endl;
		return;
	}

	long int n=r-l+1;

	long int data[n];

	for (int i = 0; i < n; ++i){
		data[i]=a[l+i];
		cout << data[i] << " :" ;
	}

	sort(data,data+n);

	int flag=0;

	if (data[n-1] == (data[n-2]+data[n-3]))
		flag=1;

	for (int i = 0; i < ; ++i)
	{
		/* code */
	}

	if (n==3 && flag==1)
		cout << "0" << endl;
	else if (flag ==1)
		cout << data[n-1]+data[n-2]+data[n-4] << endl;
	else
		cout << data[n-1]+data[n-2]+data[n-3] << endl;

	return;
}

void call(){

	int n,q;
	cin >> n >> q;

	long int a[n];

	for (int i = 0; i < n; ++i)
		cin >> a[i];

	long int n1,n2,n3;

	for (int i = 0; i < q; ++i)
	{
		cin >> n1 >> n2 >> n3;

		if ( n1==1 ) 
			a[n2-1]=n3;

		else
			call1(a,n2-1,n3-1);
	}

	return;
}

int main(){

	int t=1;

	for (int i = 0; i < t; ++i)
		call();

	return 0;
}