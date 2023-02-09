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
int getMaxPathSum(TreeNode *root, int &max)
{
    if (root == NULL)
        return 0;

    int left = getMaxPathSum(root->left, max);
    int right = getMaxPathSum(root->right, max);

    if (left < 0) left = 0;
    if (right < 0) right = 0;
       
    max = std::max(max, left + right + root->val);
    return std::max(left, right) + root->val;
}
    
    int maxPathSum(TreeNode* root) {
        
    int max = INT_MIN;
    getMaxPathSum(root, max);

    return max;    
    }
};