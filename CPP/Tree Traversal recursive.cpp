#include<iostream>

using namespace std;

struct Node
{
	int key;
	Node *left,*right;
	Node(int key)
	{
		this->key=key;
		left=right=NULL;
	}
	
};

/*Depth first Traversals :-
1) inorder
2) preorder
3) postorder
*/

void inorder(Node *root)
{
	if(root)
	{
		inorder(root->left);
		cout<<root->key<<" ";
		inorder(root->right);
	}
}

void preorder(Node *root)
{
	if(root)
	{
		cout<<root->key<<" ";
		preorder(root->left);
		preorder(root->right);
	}
}

void postorder(Node *root)
{
	if(root)
	{
		postorder(root->left);
		postorder(root->right);
		cout<<root->key<<" ";
	}	
}

int main()
{
	Node *root=new Node(10);
	root->left=new Node(20);
	root->right=new Node(30);
	root->left->left=new Node(40);
	root->left->right=new Node(50);
	root->right->left=new Node(60);
	
	cout<<"Printing Inorder:-\n";
	inorder(root);
	
	cout<<"\n\nPrinting Preorder:-\n";
	preorder(root);
	
	cout<<"\n\nPrinting Postorder:-\n";
	postorder(root);
}