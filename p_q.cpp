#include <bits/stdc++.h>
using namespace std;

int pt(int i){
	return (i-1)/2;
}

int min(int ary[]){
	return (ary[0]);
}

void heapify(int ary[],int i,int n){

	int l=2*i+1,r=2*i+2;
	int k=i;

	if (l<=n && ary[l] < ary[i])
		i=l;

	if (r <= n && ary[r] < ary[i])
		i=r;

	if (k!=i)
	{
		swap(ary[k],ary[i]);
		heapify(ary,i,n);
	}

	return;
}



void extmin(int ary[],int *N){

	int k=ary[0];

	ary[0]=ary[*N];
	(*N)--;

	heapify(ary,0,*N);

	return;
}

void dec(int ary[], int t , int i){

	if (t>ary[i]){
		return;
	}
	
	while(i>0 && ary[pt(i)] > ary[i]){
		swap(ary[pt(i)],ary[i]);
		i=pt(i);
	}
	
	return;
}

void insert(int ary[],int t,int *N){

	(*N)++;
	ary[*N]=t;
	dec(ary,t,*N);

	return;
}

void delet(int ary[],int *N,int i){

	ary[i]=ary[(*N)--];

	dec(ary,i,*N);
	heapify(ary,i,*N);

	return;
}

void print(int ary[]){
	
	int t=1;

	while(t < 15)
	{
		for (int i = t; i < 2*t ; ++i)
		{
			cout << ary [i-1] << " ";
		}
		printf("\n");
		t=2*t;
	}

 	return;
}

int main(){

	int *N,n=-1,t;
	N=&n;
	int ary[2000];

	insert(ary,5,N);
	insert(ary,6,N);
	insert(ary,2,N);
	delet(ary,N,2);
	insert(ary,8,N);
	insert(ary,7,N);
	delet(ary,N,2);
	insert(ary,2,N);
	insert(ary,8,N);
	insert(ary,2,N);
	delet(ary,N,2);
	insert(ary,25,N);

	

	print(ary);

	return 0;
}

/*
	srand(time(NULL));

	int *N,n=-1,t;
	N=&n;
	int ary[2000];

	for (int i = 0; i < 15; ++i)
	{
		t=rand()%100;
		insert(ary,t,N);
	}
		print(ary);

	for (int i = 0; i < 8; ++i)
	{
		extmin(ary,N);
	}
*/