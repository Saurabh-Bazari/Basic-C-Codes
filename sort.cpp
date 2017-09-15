#include <bits/stdc++.h>
using namespace std;

struct node{
	node *left;
	node *right;
	int data;
};

void bubblesort(int a[],int n){
	for(int i=0;i<n-1;i++){
		bool flag=true;
		for(int j=0;j<n-1-i;j++){
			if(a[j]>a[j+1]){
				int t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;
				flag=false;
			}
		}
		if(flag==true){
			break;
		}
	}
}

void selectionsort(int a[],int n){
	int j,t;
	for(int i=0;i<n;i++){
		t=0;
		bool flag=true;
		for(j=0;j<n-i;j++){
			if(a[t]<=a[j]){
				t=j;
				flag=false;
			}
		}
		j--;
		int q=a[t];
		a[t]=a[j];
		a[j]=q;
		if(flag==true){
			break;
		}
	}
}

void intrav(node *root, int &g, int a[]){
	if(root==NULL){
		return;
	}
	intrav(root->left,g,a);
	//cout<<root->data<<" ";
	a[g] = root->data;
	g++;
	intrav(root->right,g,a);
}

void binarytreesort(int a[],int n){
	node *q,*p=NULL;
	node *root=NULL;
	for(int i=0;i<n;i++){
		p=root;
		node* temp=new node;
		temp->left=NULL;
		temp->right=NULL;
		temp->data=a[i];
		if(p==NULL){
			root=temp;
		}
		else{
			q=NULL;
			while(p!=NULL){
				if(a[i]>p->data){
					q=p;
					p=p->right;
				}
				else{
					q=p;
					p=p->left;
				}
			}
			if(a[i]>q->data){
				q->right=temp;
			}
			else{
				q->left=temp;
			}
		}
	}
	int g=0;
	intrav(root, g, a);
}

void insertionsort(int a[],int n){
	for(int i=1;i<n;i++){
		int y=a[i];
		int j;
		for(j=i-1;j>=0 && a[j]>y;j--){
			a[j+1]=a[j];
		}
		a[++j]=y;
	}
}

void shellsort(int a[],int n){
	int h=1;
	int x=0;
	while(h<n){
		h=3*h+1;
		x++;
	}
	if(x-2<=0){
		insertionsort(a,n);
	}
	else{
		int *b = new int[x-2];
		h=1;
		for(int i=0;i<x-2;i++){
			b[i]=h;
			h=3*h+1;
		}
		for(int i=0;i<x-2;i++){
			for(int j=1;j<n;j++){
				int y=a[j];
				int k;
				for(k=j-b[i];k>=0 && a[k]>y;k-b[i]){
					a[k+b[i]]=a[k];
				}
				k=k-b[i];
				a[k]=y;
			}
		} 
	}
}

void merge(int a[],int l,int p,int u){
	int *L=new int[p-l+1];
	int *R=new int[u-p+1];
	for(int i=l;i<=p;i++){
		L[i-l]=a[i];
	}
	for(int i=p+1;i<=u;i++){
		R[i-p-1]=a[i];
	}
	int j=0,k=0;
	for(int i=l;i<=u;i++){
		if(j>=(p-l+1)){
			a[i] = R[k++];
			continue;
		}
		if(k>=(u-p)){
			a[i] = L[j++];
			continue;
		}
		if(L[j]>R[k]){
			a[i]=R[k++];
		}
		else{
			a[i]=L[j++];
		}
	}
}

void mergesort(int a[],int l,int u){
	if(u>l){
		int p=(l+u)/2;
		mergesort(a,l,p);
		mergesort(a,p+1,u);
		merge(a,l,p,u);
	}
}

int partition(int a[],int l,int u){
	//int pivot=rand(l,u);
	//int t=a[l];
	//a[l]=a[pivot];
	//a[pivot]=t;
	int pivot=l;		
	int down=l;
	int up=u;
	while(up>down){
		while(up>=down && a[down]<=a[pivot]){
			down++;
		}
		while(up>=down && a[up]>a[pivot]){
			up--;
		}
		if(up>down){
			int q=a[down];
			a[down]=a[up];
			a[up]=q;
		}
	}
	int q=a[l];
	a[l]=a[up];
	a[up]=q;
	return up;
}

void quicksort(int a[],int l,int u){
	if(u>l){
		int p=partition(a,l,u);
		quicksort(a,l,p-1);
		quicksort(a,p+1,u);
	}
}

void maxheapify(int a[],int i,int n){
	int l=2*i;
	int r=2*i+1;
	int max=i;
	if(l<=n && a[l]>a[max]){
		max=l;
	}
	if(r<=n && a[r]>a[max]){
		max=r;
	}
	if(max!=i){
		int t=a[i];
		a[i]=a[max];
		a[max]=t;
		maxheapify(a, max, n);
	}
}

void buildheap(int a[],int n){
	for(int i=n/2;i>0;i--){
		maxheapify(a,i,n);
	}
}

void heapsort(int a[],int n){
	buildheap(a,n);
	int heapsize=n;
	for(int i=n;i>1;i--){
		int t=a[i];
		a[i]=a[1];
		a[1]=t;
		heapsize--;
		maxheapify(a,1,heapsize);
	}
}

void printarray(int a[],int n){
	for(int j=0;j<n;j++){
			cout<<a[j+1]<<" ";
		}
	cout<<endl;
}

int main(){
	int n;
	cin>>n;
	int *a=new int[n+1];
	for(int i=0;i<n;i++){
		//a[i]=rand()%1000000;
		cin>>a[i+1];
	}
	//for(int i=0;i<n;i++){
		//bubblesort(a,n-i);
		//selectionsort(a,n-i);
		//binarytreesort(a,n-i);
		//insertionsort(a,n);
		//shellsort(a,n);
		//mergesort(a,0,n-i-1);
		//quicksort(a,0,n-1-i);	
		heapsort(a,n);
		printarray(a,n);
	// 	for(int j=0;j<n-1-i;j++){
	// 		a[j]=a[j+1]-a[j];
	// 	}
	// 	//printarray(a,n-i);
	// }
	// cout<<a[0]<<endl;
	return 0;
}