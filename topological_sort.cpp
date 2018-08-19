#include <bits/stdc++.h>
using namespace std;

struct node				//structure
{
	int data;
	int colour;
	int parent;
	node *next;
};

node *create(int k){			// create a node with data k

	node *temp=new node;
	temp->data=k;
	temp->colour=0;
	temp->parent=0;
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

void DFS_VISIT(node *Head[],node *a,node* &lhead){	
    
    node *temp=Head[a->data]->next;  
    Head[a->data]->colour=1;	
    
    while(temp!=NULL){				
        
        if(Head[temp->data]->colour==0)
            DFS_VISIT(Head,temp,lhead);

        temp=temp->next;
    }
    
    Head[a->data]->colour=2;

    node *t=create(a->data);

    t->next=lhead;
    lhead=t;
    
    return ;
}

int main() {
	
	int N,E;
	cin >> N>>E;
	
	node *Head[N+1];
	
	for(int i=1; i <= N ; ++i){		

	    Head[i]=create(i);
	}
	
	int n1,n2;
	
	for(int i=1; i <= E ; ++i){		
	    cin >> n1 >> n2;

	    add(Head[n1],n2);
	}

	for (int i = 1; i <= N; ++i)
	{
		node *t=Head[i];
		while(t!=NULL){
			cout << t->data << " ";
			t=t->next;
		}
		cout << endl;
	}

	node *lhead=NULL;

	for(int i=1; i <= N ; ++i){				
	    
	    if(Head[i]->colour==0){

	        DFS_VISIT(Head,Head[i],lhead);
		}
	}

	node *temp=lhead;

	while(temp!=NULL){
		cout << temp->data << " ";
		temp=temp->next;

	}
	cout << endl;

	return 0;
}