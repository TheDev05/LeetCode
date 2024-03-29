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
bool validate(TreeNode *root, long long left, long long right)
{
    if (root == NULL)
        return 0;

    if (root->val <= left || root->val >= right)
        return 1;

    if (validate(root->left, left, root->val))
        return 1;
    if (validate(root->right, root->val, right))
        return 1;

    return 0;
}
    
    bool isValidBST(TreeNode* root) {
        
    long long left = LONG_MIN, right = LONG_MAX;
    return !validate(root, left, right); 
        
    }
};