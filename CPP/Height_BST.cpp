#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;
};
int Height(node *root)
{
    // O(n) will be the time complexity
    if (root == NULL)
    {
        return -1;
    }
    return max(Height(root->left), Height(root->right)) + 1;
}
void Insert(node *&root, int data)
{
    if (root == NULL)
    {
        root = new node();
        root->data = data;
        return;
    }
    if (data < root->data)
    {
        Insert(root->left, data);
        return;
    }
    Insert(root->right, data);
    return;
}

int main()
{
    node *root = NULL;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        Insert(root, a);
    }
    cout<<Height(root);
    
    return 0;
}
