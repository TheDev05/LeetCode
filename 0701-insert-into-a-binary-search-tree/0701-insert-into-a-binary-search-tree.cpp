/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int target) {
            
    TreeNode *temp = root;
    TreeNode *result = NULL;
        
    while (temp)
    {
        if (temp->val < target)
        {
            result = temp;
            temp = temp->right;
        }
        else
            temp = temp->left;
    }
        
    if (result)
    {
        TreeNode *inox = result->right;
        result->right = new TreeNode(target);

        result->right->right = inox;
    }
    else
    {
        TreeNode *temp = new TreeNode(target);
        temp->right = root;

        root = temp;
    }

    return root;        
    }
};