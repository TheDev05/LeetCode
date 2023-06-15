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
int traverse(TreeNode *root, long long &min)
{
    if (root == NULL)
        return 0;

    if (traverse(root->left, min))
        return 1;

    if (root->val <= min)
        return 1;
    else
        min = root->val;

    if (traverse(root->right, min))
        return 1;

    return 0;
}
    
    bool isValidBST(TreeNode* root) {
        
    long long min = LONG_MIN;
    if (traverse(root, min))
        return false;
    else
        return true;
    
    }
};