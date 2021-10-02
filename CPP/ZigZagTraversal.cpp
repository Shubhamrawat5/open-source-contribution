
// ZigZag Traversal of a Binary Tree (GfG)
// Difficulty - Easy
//https://practice.geeksforgeeks.org/problems/zigzag-tree-traversal/1

class Solution
{
public:
    //Function to store the zig zag order traversal of tree in a list.
    vector<int> zigZagTraversal(Node *root)
    {
        // Code here
        vector<int> ans;
        stack<Node *> curr;
        stack<Node *> next;

        int height = 1;

        curr.push(root);

        while (!curr.empty() || !next.empty())
        {
            if (curr.empty())
            {
                stack<Node *> temp = curr;
                curr = next;
                next = temp;
                height++;
            }

            else
            {
                while (!curr.empty())
                {
                    Node *k = curr.top();
                    curr.pop();
                    ans.push_back(k->data);
                    if (height % 2 != 0)
                    {
                        if (k->left)
                            next.push(k->left);

                        if (k->right)
                            next.push(k->right);
                    }
                    else
                    {
                        if (k->right)
                            next.push(k->right);

                        if (k->left)
                            next.push(k->left);
                    }
                }
            }
        }

        return ans;
    }
};
