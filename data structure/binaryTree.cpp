#include <iostream>
#include <stdlib.h>
using namespace std;

 struct node
{

    int data;
    struct node *left;
    struct node *right;

} ;

struct node* create_node(int data)
{

    struct node *p = (struct node*)malloc(sizeof(struct node));
    p->data = data;
    p->left = NULL;
    p->right = NULL;

    return p;
}

void PreOrderTransversal( struct node *root){


    if (root != NULL){

        cout<<root->data<<endl;
        PreOrderTransversal(root->left);
        PreOrderTransversal(root->right);

    }
}

void PostOrderTransversal( struct node *root){


    if (root != NULL){

       
        PreOrderTransversal(root->left);
        PreOrderTransversal(root->right);
         cout<<root->data<<endl;

    }
}

void InOrderTransversal( struct node *root){


    if (root != NULL){

       
        InOrderTransversal(root->left);
          cout<<root->data<<endl;
        InOrderTransversal(root->right);
       

    }
}

int isbst(struct node *root){
     static struct node *prev=NULL;
     if (root !=NULL){
        if(!isbst(root->left)){
            return 0;
        }
        if(prev!=NULL && root->data <= prev->data){
            return 0;
        }
        prev = root;
        return isbst(root->right);


     }

     else{
        return 1;
     }
}

struct node * search (struct node *root , int key){
       while (root!=NULL)
       {
    
       
         if (root->data==key){
            return root;
        }
        else if (root->data < key){
            return search(root->right , key);

        }
        else{
            return search(root->left , key);
        }
       }
       return NULL;

}
int main()
{

    struct node *p1 = create_node(6);
    struct node *p2 = create_node(5);
    struct node *p3 = create_node(7);
    struct node *p4 = create_node(2);
    p1->left=p2;
    p1->right=p3;
    p2->left=p4;

    // PreOrderTransversal(p1);
    // PostOrderTransversal(p1);
       InOrderTransversal(p1);
       struct node *res;
       res=search(p1,7);
       if (res!=NULL){
        cout<< "found"<<res->data<<endl;

       }
       else {
        cout<<"not found";
       }
     
// cout<< isbst(p1);

    

    return 0;
}
