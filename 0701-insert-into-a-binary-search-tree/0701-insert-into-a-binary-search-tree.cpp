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
int insert(TreeNode *root, int key)
{
    if (root->val < key)
    {
        if (root->right == NULL)
        {
            root->right = new TreeNode(key);
            return 1;
        }

        if (insert(root->right, key))
            return 1;
    }
    else
    {
        if (root->left == NULL)
        {
            root->left = new TreeNode(key);
            return 1;
        }

        if (insert(root->left, key))
            return 1;
    }

    return 0;
}
    
    TreeNode* insertIntoBST(TreeNode* root, int key) {
    
    if(root == NULL) return new TreeNode(key);
    
    insert(root, key); 
    return root;
        
    }
};