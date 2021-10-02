// Children Sum Property of a Binary Tree
/*
    According to the Children sum property : Sum of values of the left child 
    and the right child for every node is equal to the value of the corresponding root.  
*/
#include<iostream>
using namespace std;

//Structure of Binary 
struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};
// Function to check for Children Sum Property
bool is_children_sum(Node* root){
    if(root == NULL)
        return true;
    if(root->left == NULL && root->right == NULL)
        return true;
    
    int sum = 0;
    if(root->left != NULL)
        sum += (root->left->data);
    if(root->right != NULL)
        sum += (root->right->data);
    
    bool left = is_children_sum(root->left);
    bool right = is_children_sum(root->right);

    return (root->data == sum && left && right);
}

int main(){
    Node* root = new Node(20);
    root->left = new Node(8);
    root->right = new Node(12);
    root->left->left = new Node(3);
    root->left->right = new Node(5);

    if(is_children_sum(root)){
        cout<<"The tree follows children sum property "<<"\n";
    }
    else{
        cout<<"The tree doesn't follow children sum property "<<"\n";
    }
}