	

#include <bits/stdc++.h>
using namespace std;

struct node
{
	int row,col,val;
	node *right,*down;
};

node *create(int r,int c,int v){
	node *temp;
	temp=new node;
	temp->row=r;
	temp->col=c;
	temp->val=v;
	temp->right=NULL;
	temp->down=NULL;
	return temp;
}

void insert(node *temp,node **head){
	node *tr=head[temp->row];
	node *t,*tc=head[temp->col];

	if (tr==NULL)
	{
		head[temp->row]->right=temp;
	}
	// else{
	// 	while( tr!=NULL &&(tr->col < temp->col) ){
	// 		t=tr;
	// 		tr=tr->right;
	// 	}
	// 	if (t==head[temp->row])
	// 	{
	// 		temp->right=head[temp->row]->right;
	// 		head[temp->row]->right=temp;
	// 	}
	// 	else if (tr==NULL)
	// 	{
	// 		t->right=temp;
	// 	}
	// 	else{
	// 		temp->right=t->right;
	// 		t->right=temp;
	// 	}
	// }
	if (tc==NULL)
	{
		head[temp->col]->down=temp;
	}
	// else{
	// 	while( tc!=NULL && tc->row < temp->row ){
	// 		t=tc;
	// 		tc=tc->down;
	// 	}
	// 	if (t==head[temp->col])
	// 	{
	// 		temp->down=head[temp->col]->down;
	// 		head[temp->col]->down=temp;
	// 	}
	// 	else if (tc==NULL)
	// 	{
	// 		t->down=temp;
	// 	}
	// 	else{
	// 		temp->down=t->down;
	// 		t->down=temp;
	// 	}
	// }

	return;
}

void print(node *head){
	
}


int main()
{
	int r,c,v;
	cin >> r >> c >> v;
	node *head[r+c];

	for (int i = 0; i < r+c; ++i)
	{
		//head[i]=new node;
		head[i]=create(0,0,0);
	}
	int as,sd,df;
	node *temp;
	for (int i = 0; i < v; ++i)
	{
		cin >> as>> sd>>df;
		temp=create(as,sd,df);
		insert(temp,head);

	}

	for (int i = 0; i < r; ++i)
	{
		temp=head[i]->right;

		while(temp!=NULL){
			printf("%d   ",temp->val );
			temp=temp->right;
		}
		printf("\n");
	}

	return 0;
}

/*




*/