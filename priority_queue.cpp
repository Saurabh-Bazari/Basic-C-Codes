#include <bits/stdc++.h>
using namespace std;

int h=INT_MAX;

int parent(int i){
	return (i-1)/2;
}

void insert(int *start,int &size,int key){

	int *cur;
	cur=start+size;
	size++;
	cur=new int;
	start[size-1]=key;

	int k=size-1;

	while(k!=0 && start[parent(k)] > start[k] ){
		swap(start[parent(k)] , start[k]);
		k=parent(k);
	}

	return ;
}

void print(int *start,int size){

	for (int i = 0; i < size; ++i)
		cout << start[i]<<" ";

	printf("\n");
	
	return;
}

void min_heapify(int *start,int size,int k){

	int l,r,curr=k;
	l=2*k+1;
	r=2*k+2;

	if (l < size && start[curr] > start[l] )
		curr=l;

	if (r < size && start[curr] > start[r] )
		curr=r;

	if (k!=curr)
	{
		swap(start[k],start[curr]);
		min_heapify(start,size,curr);
	}

	return;
}

void Extract_min(int *start,int &size){

	if (size<0)
		return;
	
	start[0]=start[--size];
	min_heapify(start,size,0);

	return;
}

void decrease_key(int *start,int size,int index,int key){

	if (start[index] < key )
		return;

	start[index]=key;

	// min_heapify(start,size,index); 

	while(index > 0 && start[parent(index)] > start[index]){
		swap(start[parent(index)] , start[index]);
		index=parent(index);
	}



	return;
}

void Delete(int *start,int &size,int index){

	decrease_key(start,size,index,-h);
	Extract_min(start,size);

	return;
}


int main(){

	srand(time(NULL));

	int *start;
	int size=0;
	int k;

	for (int i = 0; i < 15 ; ++i)
	{
		k=rand()%100;
		insert(start,size,k);
	}

	print(start,size);
	Extract_min(start,size);
	Delete(start,size,4);
	print(start,size);


	return 0;
}