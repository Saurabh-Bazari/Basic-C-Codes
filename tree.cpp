#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
	int data;
	struct _node *left;
	struct _node *right;
}node;

node * createnode(int d)
{
	node *temp = (node *)malloc(sizeof(node));
	temp->data = d;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

void input(node **root, int d)
{
	//printf("yy\n");
	if(*root == NULL)
	{
		*root = createnode(d);
		return;
	}

	if(d > (*root)->data)
	{
		input(&((*root)->right), d);
		return;
	}
	if(d < (*root)->data)
		input(&((*root)->left), d);
}

void printTree(node *root)
{
	//	printf("yy\n");

	if(root == NULL)
		return;
	
	printTree(root->left);
	
	printTree(root->right);
	printf("%d ",root->data );
}

int findleave(node *root)
{
	if(root == NULL)
		return 0;
	if(root->left == NULL && root->right == NULL )
		return 1;
	return  findleave(root->left) + findleave(root->right);

}

int main()
{
	node *root = NULL;
	int i;

	for(i = 0;i<15;i++)
		input(&root, rand()%50);

	printf("\n%d\n",findleave(root));
	printTree(root);

}