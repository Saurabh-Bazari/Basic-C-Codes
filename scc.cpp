#include <bits/stdc++.h>
using namespace std;

struct node				//structure
{
	int data;
	int colour;
	node *next;
};

node *create(int k){			// create a node with data k

	node *temp=new node;
	temp->data=k;
	temp->colour=0;
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

void DFS_VISIT(node *Head[],node *a,node* &lhead,int d[],int f[],int &time){	
   
    node *temp=Head[a->data]->next;  
    Head[a->data]->colour=1;
    d[a->data]=++time;	
    
    while(temp!=NULL){				
        
        if(Head[temp->data]->colour==0)
            DFS_VISIT(Head,temp,lhead,d,f,time);

        temp=temp->next;
    }
    
    Head[a->data]->colour=2;

    f[a->data]=++time;

    node *t=create(a->data);

    t->next=lhead;
    lhead=t;
    
    return ;
}

void DFS_VISIT1(node *Head1[],node *a){	
    
    node *temp=Head1[a->data]->next;  
    Head1[a->data]->colour=1;	
    
    while(temp!=NULL){				
        
        if(Head1[temp->data]->colour==0){
        	cout << temp->data << " ";
            DFS_VISIT1(Head1,temp);
        }

        temp=temp->next;
    }
    
    Head1[a->data]->colour=2;
    
    return ;
}

int main() {
	
	int N,E;
	cin >> N>>E;
	
	node *Head[N+1];
	node *Head1[N+1];
	
	for(int i=1; i <= N ; ++i){		

	    Head[i]=create(i);
	    Head1[i]=create(i);

	}
	
	int n1,n2;
	
	for(int i=1; i <= E ; ++i){		
	    cin >> n1 >> n2;

	    add(Head[n1],n2);
	    add(Head1[n2],n1);
	}

	node *lhead1=NULL,*lhead=NULL;

	int d[N+1]={0},f[N+1]={0},time=0;

	for(int i=1; i <= N ; ++i){				
	    
	    if(Head[i]->colour==0){

	        DFS_VISIT(Head,Head[i],lhead,d,f,time);
		}
	}

	node *temp1=lhead;

	while(temp1!=NULL){

		if (Head1[temp1->data]->colour==0)
		{
			        	cout << temp1->data << " ";

			DFS_VISIT1(Head1,Head1[temp1->data]);

			cout << endl;
		}

		//cout << temp1->data;

		temp1=temp1->next;

	}
	
	cout << endl;

	return 0;
}	   
