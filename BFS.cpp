#include <bits/stdc++.h>
using namespace std;

struct node_edge
{
	int e;
	node_edge *e1;
	node_edge *e2;	
};

struct node
{
	int data;
	node *next;
};

node *create(int k){

	node *temp=new node;
	temp->data=k;
	temp->next=NULL;
	return temp;
}

void add(node *a,int k){

	node *temp=create(k);
	node *t=a;

	if (a->next==NULL)
	{
		a->next=temp;
		temp->next=NULL;
		return;
	}

	while(t->next!=NULL)
		t=t->next;
	
	t->next=temp;
	temp->next=NULL;	

	return;
}

void BFS(node_edge * E_list[],node *Adj[], int n,int e,int s){

	int colour[n]={0},d[n]={0},parent[n],u=0,v=0;

	d[s]=0;
	colour[s]=1;

	node *head,*temp;
	head=create(s);

	while(head!=NULL){

		u=head->data;
		head=head->next;

		temp=Adj[u]->next;

		while(temp!=NULL){

			v=temp->data;

			cout << "u= " << u << endl;
			cout << "v= " << v << endl << endl;

			if (colour[v]==0)
			{
				if (head==NULL)
					head=create(v);

				else
					add(head,v);
				
				colour[v]=1;
				d[v]=d[u]+1;
				parent[v]=u;
			}
			colour[u]=-1;
			temp=temp->next;
		}
	}

	for (int i = 0; i < n; ++i)
	{
		cout << d[i] << " ";
	}
	printf("\n");

	return;
}


int main()
{
	int n,e,n1,n2;
	cin >> n >> e;

	node_edge *E_list[e];
	node_edge *v_mapping[n];

	for (int i = 0; i <n ; ++i){

		v_mapping[i]=new node_edge;
		v_mapping[i]->e=i+1;
	}

	for (int i = 0; i < e; ++i)
	{
		E_list[i]=new node_edge;

		E_list[i]->e=i+1;
		cin >> n1 >> n2;

		E_list[i]->e1=v_mapping[n1-1];
		E_list[i]->e2=v_mapping[n2-1];
	}

	// for (int i = 0; i < e; ++i)
	// {
	// 	cout << E_list[i]->e<< " " << E_list[i]->e1->e << " " << E_list[i]->e2->e << endl;
	// }

	node *Adj[n];

	for (int i = 0; i < n; ++i)
		Adj[i]=create(i+1);
	

	for (int i = 0; i < e; ++i)
	{
		n1=E_list[i]->e1->e;
		n2=E_list[i]->e2->e;

		add(Adj[n1-1],n2);
	}

	node *temp;

	for (int i = 0; i < n; ++i)
	{
		temp=Adj[i];

		while(temp!=NULL){

			cout << temp->data << " ";
			temp=temp->next;
		}
		printf("\n");
	}

	BFS(E_list,Adj,n,e,1);

	return 0;
}