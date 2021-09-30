class Solution {
    bool validate(TreeNode* root, TreeNode* min, TreeNode *max)
    {
        if(root == NULL)
            return true;
        
        if( (min && root->val <= min->val) ||
            (max && root->val >= max->val) )
            return false;
        
        return validate(root->left, min, root) &&
               validate(root->right, root, max);
    }

public:
    bool isValidBST(TreeNode* root) {
        
        return validate(root, NULL, NULL);
        
    }
};
