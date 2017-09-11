/*nclude <bits/stdc++.h>
using namespace std;

struct matrix
{
	int r;
	int c;
	int v;
};

int main()
{
	int r1,c1,n;
	cin >> n;

	matrix  m[n+1];

	int j=0;

	for (int i = 0; i < n; ++i)
	{
		cin >> m[i].r >> m[i].c >> m[i].v;
	}

	for (int i = 1; i <= n; ++i)
	{
		if (j<m[i].c)
		{
			j=m[i].c
		}
	}
	j++;
	int col[j];
	
	for (int i = 0; i < j; ++i)
	{
		col[i]=0;
	}

	for (int i = 0; i < n; ++i)
	{
		col[m[i+1].c]++;
	}
	int k=1,t1=0;


	for (int i = 0; i < j; ++i)
	{
		t1=col[i];
		col[i]=k;
		k=t1+k;
	}

	for (int i = 0; i < j; ++i)
	{
		printf("%d\n",col[i] );
	}

	// for (int i = 1; i <= n; ++i)
	// {
	// 	m1[col[m[i].c]].r=m[i].c;
	// 	m1[col[m[i].c]].c=m[i].r;
	// 	m1[col[m[i].c]].v=m[i].v;

	// 	col[m[i].c]++;
	// }






	return 0;
}


#include <bits/stdc++.h>
using namespace std;

struct matrix
{
	int row;
	int coloum;
	int value;
};

void change(matrix *m,matrix *m1,int i,int j){

	m1[j].row=m[i].coloum;
	m1[j].coloum=m[i].row;
	m1[j].value=m[i].value;

	return;
}

int main()
{
	int n,k,j;
	cin >> n;
	matrix *m;
	n++;
	m= new matrix [n];

	for (int i = 1; i < n; ++i)
	{
		cin >> m[i].row >> m[i].coloum >> m[i].value ;
	}

	matrix m1[n+1];
	m1[2].coloum=h;
	change(m,m1,1,1);


	for (int i = 2; i < n; ++i)
	{
		int j=1;
		cout << m[i].coloum << "  "  << m1[j].coloum <<"  "<<endl;
		
		while(m[i].coloum <= m1[j].coloum){
			j++;
		}
		cout << "j=" << j << endl;
		k=j;
		while(j<n){

			m1[j+1]=m1[j];
			j++;
		}
		change(m,m1,i,k);
	}



printf("Transpose of martix is:\n");


	for (int i = 1; i <= n; ++i)
	{
		cout << m1[i].row << " " << m1[i].coloum << " " << m1[i].value << endl; 
	}
	printf("\n");

	return 0;
}

/*

8
0 0 15
0 3 22
0 5 -15
1 1 11
1 2 3
2 3 -6
4 0 91
5 2 28


4 5 8
5 2 28
0 3 22
1 1 11
0 5 -15
1 2 3
4 0 91
2 3 -6
0 0 15







#include <bits/stdc++.h>
using namespace std;

struct matrix
{
	int row;
	int coloum;
	int value;
};

int main()
{
	int n;
	cin >> n;
	n++;
	matrix m[1000];

	for (int i = 1; i < n; ++i)
	{
		cin >> m[i].row >> m[i].coloum >> m[i].value ;
	}

	int n1;
	cin >> n1;
	n1++;
	matrix m1[1000];

	for (int i = 1; i < n1; ++i)
	{
		cin >> m1[i].row >> m1[i].coloum >> m1[i].value ;
	}

	int j;

	for (int i = 1; i < n; ++i)
	{
		for (j = 1; j < n1; ++j)
		{

			if ((m[i].row==m1[j].row && m[i].coloum==m1[j].coloum))
			{
				break;
			}
		}
		
			if (j==n1)
			{
				m1[n1].row=m[i].row;
				m1[n1].coloum=m[i].coloum;
				m1[n1].value=m[i].value;
				n1++;
			}

			else{
				m1[j].value=m[i].value + m1[j].value ;
			}
	}



	







	printf("SUM : \n");
	for (int i = 1; i < n1; ++i)
	{
		cout << m1[i].row << " " << m1[i].coloum << " " << m1[i].value <<endl;
	}





	return 0;
}












/*

8
0 0 15
0 3 22
0 5 -15
1 1 11
1 2 3
2 3 -6
4 0 91
5 2 28


4
0 0 1
0 1 6
1 0 7
1 1 4
4
0 0 6
0 1 4
1 0 7
1 1 5






#include <bits/stdc++.h>
using namespace std;

struct matrix
{
	int r;
	int c;
	int v;
};

int main()
{
	int r1,c1,n;
	cin >> n;

	matrix  m[n+1];

	int j;

	for (int i = 0; i < n; ++i)
	{
		cin >> m[i].r >> m[i].c >> m[i].v;
	}


	for (int i = 0; i < n ; ++i)
	{
		m[n]=m[i];
		for ( j = i-1; j >= 0 && m[n].c < m[j].c ; --j)
		{
			m[j+1]=m[j];
		}
		m[j+1]=m[n];
	}
	for (int i = 0; i < n ; ++i)
	{
		m[n]=m[i];
		for ( j = i-1; j >=0 && m[n].r < m[j].r ; --j)
		{
			m[j+1]=m[j];
		}
		m[j+1]=m[n];
	}




	

	for (int i = 1; i < n+1; ++i)
	{
		cout << m[i].r << "   " << m[i].c << "   " <<m[i].v <<endl;
	}

	
	return 0;
}



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




















#include <bits/stdc++.h>
using namespace std;

struct matrix
{
	int r;
	int c;
	int v;
};

int main()
{
	int r1,c1,n;
	cin >> n;

	matrix  m[n+1];

	int j=0;

	for (int i = 0; i < n; ++i)
	{
		cin >> m[i].r >> m[i].c >> m[i].v;
	}

	for (int i = 1; i <= n; ++i)
	{
		if (j<m[i].c)
		{
			j=m[i].c
		}
	}
	j++;
	int col[j];
	
	for (int i = 0; i < j; ++i)
	{
		col[i]=0;
	}

	for (int i = 0; i < n; ++i)
	{
		col[m[i+1].c]++;
	}
	int k=1,t1=0;


	for (int i = 0; i < j; ++i)
	{
		t1=col[i];
		col[i]=k;
		k=t1+k;
	}

	for (int i = 0; i < j; ++i)
	{
		printf("%d\n",col[i] );
	}

	// for (int i = 1; i <= n; ++i)
	// {
	// 	m1[col[m[i].c]].r=m[i].c;
	// 	m1[col[m[i].c]].c=m[i].r;
	// 	m1[col[m[i].c]].v=m[i].v;

	// 	col[m[i].c]++;
	// }






	return 0;
}


#include <bits/stdc++.h>
using namespace std;

struct matrix
{
	int row;
	int coloum;
	int value;
};

void change(matrix *m,matrix *m1,int i,int j){

	m1[j].row=m[i].coloum;
	m1[j].coloum=m[i].row;
	m1[j].value=m[i].value;

	return;
}

int main()
{
	int n,k,j;
	cin >> n;
	matrix *m;
	n++;
	m= new matrix [n];

	for (int i = 1; i < n; ++i)
	{
		cin >> m[i].row >> m[i].coloum >> m[i].value ;
	}

	matrix m1[n+1];
	m1[2].coloum=h;
	change(m,m1,1,1);


	for (int i = 2; i < n; ++i)
	{
		int j=1;
		cout << m[i].coloum << "  "  << m1[j].coloum <<"  "<<endl;
		
		while(m[i].coloum <= m1[j].coloum){
			j++;
		}
		cout << "j=" << j << endl;
		k=j;
		while(j<n){

			m1[j+1]=m1[j];
			j++;
		}
		change(m,m1,i,k);
	}



printf("Transpose of martix is:\n");


	for (int i = 1; i <= n; ++i)
	{
		cout << m1[i].row << " " << m1[i].coloum << " " << m1[i].value << endl; 
	}
	printf("\n");

	return 0;
}

/*

8
0 0 15
0 3 22
0 5 -15
1 1 11
1 2 3
2 3 -6
4 0 91
5 2 28


4 5 8
5 2 28
0 3 22
1 1 11
0 5 -15
1 2 3
4 0 91
2 3 -6
0 0 15








#include <bits/stdc++.h>
using namespace std;

struct matrix
{
	int row;
	int coloum;
	int value;
};

int main()
{
	int n;
	cin >> n;
	n++;
	matrix m[1000];

	for (int i = 1; i < n; ++i)
	{
		cin >> m[i].row >> m[i].coloum >> m[i].value ;
	}

	int n1;
	cin >> n1;
	n1++;
	matrix m1[1000];

	for (int i = 1; i < n1; ++i)
	{
		cin >> m1[i].row >> m1[i].coloum >> m1[i].value ;
	}

	int j;

	for (int i = 1; i < n; ++i)
	{
		for (j = 1; j < n1; ++j)
		{

			if ((m[i].row==m1[j].row && m[i].coloum==m1[j].coloum))
			{
				break;
			}
		}
		
			if (j==n1)
			{
				m1[n1].row=m[i].row;
				m1[n1].coloum=m[i].coloum;
				m1[n1].value=m[i].value;
				n1++;
			}

			else{
				m1[j].value=m[i].value + m1[j].value ;
			}
	}



	
//sum






	printf("SUM : \n");
	for (int i = 1; i < n1; ++i)
	{
		cout << m1[i].row << " " << m1[i].coloum << " " << m1[i].value <<endl;
	}





	return 0;
}












/*

8
0 0 15
0 3 22
0 5 -15
1 1 11
1 2 3
2 3 -6
4 0 91
5 2 28


4
0 0 1
0 1 6
1 0 7
1 1 4
4
0 0 6
0 1 4
1 0 7
1 1 5






#include <bits/stdc++.h>
using namespace std;

struct matrix
{
	int r;
	int c;
	int v;
};

int main()
{
	int r1,c1,n;
	cin >> n;

	matrix  m[n+1];

	int j;

	for (int i = 0; i < n; ++i)
	{
		cin >> m[i].r >> m[i].c >> m[i].v;
	}


	for (int i = 0; i < n ; ++i)
	{
		m[n]=m[i];
		for ( j = i-1; j >= 0 && m[n].c < m[j].c ; --j)
		{
			m[j+1]=m[j];
		}
		m[j+1]=m[n];
	}
	for (int i = 0; i < n ; ++i)
	{
		m[n]=m[i];
		for ( j = i-1; j >=0 && m[n].r < m[j].r ; --j)
		{
			m[j+1]=m[j];
		}
		m[j+1]=m[n];
	}




	

	for (int i = 1; i < n+1; ++i)
	{
		cout << m[i].r << "   " << m[i].c << "   " <<m[i].v <<endl;
	}

	
	return 0;
}



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


#include <bits/stdc++.h>

using namespace std;

// Structure of a node
struct Node
{
    Node *Down , *Right ;//  pointers to the nodes down of this node and right of this node 
    int row , col  ,val;//  Stores the row & column number of the node and the value to be stored in that position 
};

// SparseMatrix class to implement the Sparse matrix 
class SparseMatrix
{
private:
	Node Root;// stores the number of rows , columns , elements in the matrix
	Node **Heads;// pointer to an array of Nodes pointers which points to the Heads(i.e. the starting of rows and cols)
public:
	SparseMatrix(int row , int col , int elements); // Constructor
	Node *CreateNode(int row , int col , int val); // Create a node with the given arguments as its properties
	void BuildMatrix(); // build the matrix using random positions and random values
	bool InsertNode(Node *NodeToInsert); // Insert the node to the matrix
	int RandomRow(); // returns a random value of the possible row number 
	int RandomCol(); // returns a random value of the possible column number
	int RandomVal(); // returns a random number for the value ot be stored
	Node * HighsetValue(); // returns a pointer to the node which has highest value
};

int main()
{
	//Seed the random fucntion
	srand(time(NULL));

	// input the following properties from the user
    int row , col , elements;
    cout<<"Enter the number of Rows:\t";
    cin>>row;
    cout<<"Enter the number of Columns:\t";
    cin>>col;
    cout<<"Enter the number of Elements:\t";
    cin>>elements;

    // if the number of elements input by user are greater than the capacity of the sparse matrix , quit the program with an error
    if (elements > row*col)
    {
    	cout<<"ERROR OVERFLOW : Number of elements entered is more than the size of the sparse matrix."<<endl;
    	return 0;
    }
    if (elements < 0)
    {
    	cout<<"ERROR : Please enter valid number of elements."<<endl;
    	return 0;
    }

    // Declare a empty sparse matrix
    SparseMatrix SM(row ,col ,elements);
    // cout<<"Sparse Matrix Constructor Run Successfully"<<endl;

    //Construct a sparse matrix with k random values inserted at k random positions in the sparse matrix
    SM.BuildMatrix();
    // cout<<"Sparse Matrix Built Successfully"<<endl;

    // find the node with the highest value
    Node * HightestValNode = SM.HighsetValue();
    if (HightestValNode == NULL)
    {
    	cout<<"Sparse Matrix is empty."<<endl;
    	cout<<"Hence there is no highest value."<<endl;
    }
    else
    {
	    cout<<"Highest value in the sparse matrix is:\t"<<HightestValNode->val<<endl;
	}
    return 0;
}

//Constructor of the SparseMatrix Class
SparseMatrix::SparseMatrix(int row , int col , int elements)
{
	//Root of the sparse matrix stores the number of rows , columns and the number of elements in the matrix.
	Root.row = row;
	Root.col = col;
	Root.val = elements;

	// number of headers to make is the maximum of the number of the rows and columns
	int n = max(row , col);
	Heads = new Node*[n+1];

	// allocate memory for each head
	for (int i = 1; i <= n; ++i)
	{
		Heads[i] = new Node;
	}

	// Root points to the first head of the row and column
	Root.Down = Heads[1];
	Root.Right = Heads[1];

	//Set the different properties and values of the different heads
	int i;
	for (i = 1; i <= n; ++i)
	{
		//Initially the head points to themselves like a circular queue
		Heads[i]->Down = Heads[i];
		Heads[i]->Right = Heads[i];

		//we store 0 in the row,col,val of the headers....they denote nothing...just some value
		// these value helps when finding the correct poistion for the new node to store(check the insert node funciton for better understanding)
		Heads[i]->row = 0;
		Heads[i]->col = 0;
		Heads[i]->val = 0;
	}
}

// Create a node with the given arguments as its properties
Node* SparseMatrix::CreateNode(int row , int col , int val)
{
	// allocate memory for the new node
	Node * temp = new Node;
	//update it's values
	temp->row = row;
	temp->col = col;
	temp->val = val;
	return temp ;
}

// build the matrix using random positions and random values
void SparseMatrix::BuildMatrix()
{
	// counter is to count the number of elements stroed in the sparse matrix
	int Counter = 0;

	// maximum number of elements to be stored in the matrix is given by the user
	while(Counter < Root.val)
	{
		// random row number , column number , value to be stored in that position
		int i , j , val;
		i = RandomRow();
		j = RandomCol();
		val = RandomVal();

		// create a node with that properties
		Node *temp = CreateNode(i , j , val);
		
		// insert it in the sparse matrix
		if(InsertNode(temp))
		{
			Counter++;
		}
		else// it returns false if that posiiton is already occupied.(BCZ of random function.)
		{
			delete(temp);// free that memory
		}
	}
}

// Insert the node to the matrix
bool SparseMatrix::InsertNode(Node *NodeToInsert)
{
	int row = NodeToInsert->row;// the row to insert the node to
	int col = NodeToInsert->col;// the column to insert the node to

	// first updating the matrix the column
	Node * ColPtr1 = Heads[col];
	Node * ColPtr2 = ColPtr1->Down;
	// traverse the column once to find the correct position
	while(ColPtr2 != Heads[col] && ColPtr1->row < row)
	{
		ColPtr1 = ColPtr2;
		ColPtr2 = ColPtr2->Down;
	}
	if (ColPtr1->row == row)// if that position is already occupied , return false
	{
		return false;
	}

	// now updating the sparse matrix along the rows
	Node * RowPtr1 = Heads[row];
	Node * RowPtr2 = RowPtr1->Right;
	// traverse the row once to find the correct position
	while(RowPtr2 != Heads[row] && RowPtr1->col < col)
	{
		RowPtr1 = RowPtr2;
		RowPtr2 = RowPtr2->Right;
	}
	if (RowPtr1->col == col)// if that position is already occupied , return false
	{
		return false;
	}

	// Update the down and right pointers of the required nodes
	// (i.e. add the required node to it's required position). 
	ColPtr1->Down = NodeToInsert;
	NodeToInsert->Down = ColPtr2;	
	RowPtr1->Right = NodeToInsert;
	NodeToInsert->Right = RowPtr2;
	//return true to denote that node is inserted in its correct position
	return true;
}

// random valid row number
int SparseMatrix::RandomRow()
{
	return rand()%Root.row +1;
}
// random valid column number
int SparseMatrix::RandomCol()
{
	return rand()%Root.col +1;
}
// random value
int SparseMatrix::RandomVal()
{
	return rand()%1000000 +1;
}

// to find th enode witht he highest value
Node * SparseMatrix::HighsetValue()
{
	int max = INT_MIN;// initialise the highest value to INF_MIN
	Node * HightestValNode = NULL;
	for (int i = 1; i <= Root.row; ++i)// find along the rows starting from the first row
	{
		//traverse along each row once to update the highest value node.
		Node * NodePtr = Heads[i]->Right;
		while(NodePtr != Heads[i])
		{
			if (NodePtr->val > max)
			{
				max = NodePtr->val;
				HightestValNode = NodePtr;
			}
			NodePtr = NodePtr->Right;
		}
	}
	return HightestValNode;
}












*/





