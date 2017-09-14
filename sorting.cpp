#include <bits/stdc++.h>
using namespace std;

void bubble(int a[],int n){

	int as[n];

	for (int i = 0; i < n; ++i)
	{
		as[i]=a[i];
	}


	for (int i = 0; i < n-1; ++i)
	{
		for (int j = 0; j < n-i-1; ++j)
		{
			if (as[j]>as[j+1])
				swap(as[j],as[j+1]);
		}
	}

	printf("\n");

	for (int i = 0; i < n; ++i)
	{
		cout << as[i]<<" ";
	}

	return ;
}

void selection(int a[],int n){

	int as[n];

	for (int i = 0; i < n; ++i)
	{
		as[i]=a[i];
	}

	
	int index;

	for (int i = 0; i < n-1; ++i)
	{
		index=0;

		for (int j = 1; j < n-i; ++j)
		{
			if (as[index]<a[j])
				index=j;
			
		}
		swap(as[n-i-1],as[index]);
	}

	printf("\n");

	for (int i = 0; i < n; ++i)
	{
		cout << as[i]<<" ";
	}

	return;
}

int main()
{
	srand(time(NULL));

	int n;
	cin >> n;

	int a[n];

	for (int i = 0; i < n; ++i)
	{
		a[i]=n-i;
	}

	bubble(a,n);
	selection(a,n);

	printf("\n");

	for (int i = 0; i < n; ++i)
	{
		cout << a[i] <<" ";
	}

	printf("\n");

	return 0;
}

// binary sort

#include <bits/stdc++.h>
using namespace std;

struct treenode
{
	int data;
	treenode *left;
	treenode *right;
};

void insert(int a,treenode **start){

	treenode *t,*t2,*t1=(*start);
	t=new treenode;
	t->data=a;
	t->left=NULL;
	t->right=NULL;

	int w=0;

	if ((*start)==NULL)
	{
		(*start)=t;
		return;
	}
	else{

		while(t1!=NULL){
			t2=t1;

			if( t1->data < a )
			{
				w=1;
				t1=t1->right;
			}
			else{
				w=0;
				t1=t1->left;
			}
		}

		if (w==1)
		{
			t2->right=t;
		}
		else{
			t2->left=t;
		}

	}
	return;
}

void inorder(treenode *start){

	if (start==NULL)
	{
		return;
	}

	inorder(start->left);
	printf("%d ",start->data );
	inorder(start->right);

	return;
}

void binary_tree(int a[],int n){

	treenode *start=NULL;

	for (int i = 0; i < n; ++i)
	{
		insert(a[i],&start);
	}

	//printf("%d\n",start->data );

	inorder(start);

	return ;
}

int main()
{
	int n;
	cin >> n;

	int a[n];

	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}

	binary_tree(a,n);

	return 0;
}

// insertion Sort

for (int i = 0; i < n; ++i)
{
	y=a[i];

	for (int j = i-1 ; j >=0 && y < a[j] ; ++j)
	{
		a[j+1]=a[j];
	}
	a[j+1]=y;
}

// shell sort

void shell_sort(int a[],int n){

	int temp,j;

	for (int gap = n/2 ; gap > 0; gap=gap/2	)
	{
		for (int i = gap; i < n; ++i)
		{
			temp=a[i];

			for ( j = i-gap ; j >= 0 && temp< a[j] ; j=j-gap)
			{
				a[j+gap]=a[j];
			}
			a[j+gap]=temp;
		}
	}

	return;
}

// merge

int h=INT_MAX;

void merge(int a[],int l,int p,int n){

	int n1,n2;

	n1=p-l+1;
	n2=n-p; 

	int L[n1+1];
	L[n1]=h; 

	int r[n2+1];
	r[n2]=h;

	for (int i = 0; i < n1; ++i)
	{
		L[i]=a[l+i];
	}

	for (int i = 0; i < n2; ++i)
	{
		r[i]=a[p+1+i];
	}	

	int j=0,k=0;

	for (int i = l; i <= n ; ++i)
	{
		if( L[j] > r[k] )
			a[i]=r[k++];

		else
			a[i]=L[j++];
	}

	return;
}

void merge_sort(int a[] ,int l,int n){

	int p;

	if (l<n)
	{
		p=(l+n)/2;
		merge_sort(a,l,p);
		merge_sort(a,p+1,n);
		merge(a,l,p,n);
	}

	return;
}

// quick sort


int partion(int a[],int l,int u){

	int down=l ,up=u;
	int p=a[l];

	while(down < up){

		while( a[down] <= p )
			down++;

		while(a[up] > p)
			up--;

		if (down < up){
			swap(a[down],a[up]);
		}
	}

	swap(a[l],a[up]);

	return up;
}

void quick(int a[],int l,int u){

	int j;

	if (l<u)
	{
		j=partion(a,l,u);
		quick(a,l,j-1);
		quick(a,j+1,u);
	}

	return;
}

// Heap Sort



void heap(int a[],int n,int i){

	int large=i;
	int l=2*i+1;
	int r=2*i+2;

	if (l < n && a[l] > a[large] )
	{
		large =l;
	}
	if (r < n && a[r] > a[large])
	{
		large = r;
	}
	if (large !=i ){
		swap (a[large],a[i]);
		heap(a,n,large);
	}

	return;
}


void heap_sort(int a[],int n){

	for (int i = (n/2) -1 ; i >= 0 ; --i)
	{
		heap(a,n,i);
	}

	for (int i = 0; i < n-1; ++i)
	{
		swap(a[0],a[n-i-1]);
		heap(a,n-i-1,0);
	}


	return;
}