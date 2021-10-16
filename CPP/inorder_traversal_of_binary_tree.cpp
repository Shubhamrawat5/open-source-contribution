# include <iostream>
# include <algorithm>
using namespace std;

class node
{
	public:
	char c;
	node *l;
	node *r;
};

node *crtnode(char x)
{
	node *p=new node;
	p->c=x;
	p->l=p->r=NULL;
	return p;
}

void inorder(node *p)//left,root,right
{
	if(p==NULL)
		return;
	inorder(p->l);
	cout<<p->c<<" ";
	inorder(p->r);
	return;

}

int main()
{
	node *root=crtnode('c');
	root->l=crtnode('t');
	root->r=crtnode('e');
	root->l->l=crtnode('g');
	root->r->r=crtnode('a');

	cout<<"\nThe inorder traversal is: "<<endl;
	inorder(root);

	return 0;

}