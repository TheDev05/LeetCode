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
TreeNode *traverse(TreeNode *root)
{
    if (root == NULL)
        return NULL;

    TreeNode *dash1 = traverse(root->left);
    TreeNode *dash2 = traverse(root->right);

    root->left = dash1;
    root->right = dash2;

    if (dash1 == NULL && dash2 == NULL && root->val == 0)
        return NULL;

    return root;
}
    
    TreeNode* pruneTree(TreeNode* root) {
    return traverse(root);
    }
};