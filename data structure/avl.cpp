#include <iostream>
#include<stdlib.h>
using namespace std;

struct node {
      
       int data;
       struct node * left;
       struct node * right;
       int height;

};

struct node * create( ){

    struct node * n=(struct node *) malloc(sizeof(struct node));;
    int data;
    cout<<"Enter data to be inserted:";
    cin >> data;
    n->data=data;
    n->right=NULL;
    n->left=NULL;
    n->height=1;
    return n;
}

int getheight(struct node *root){
    if (root ==NULL){
        return 0;
    }

    return root->height;
}



int main()
{

    struct node *root, *n1,*n2;
    root=create();
    n1=create();
    n2=create();
    root->left=n1;
    n1->left=n2;
    cout<<getheight(root);
return 0;
}
