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
int traverse(TreeNode *root, int &sum)
{
    if (root == NULL)
        return 0;

    int left = traverse(root->left, sum);
    int right = traverse(root->right, sum);
    sum = std::max(sum, root->val);
    
    if(left>0 && right>0)
        sum=std::max(sum, root->val+left+right);
    else if(left>0)
        sum=std::max(sum, root->val+left);
    else if(right>0)
        sum=std::max(sum, root->val+right);
    
    if(std::max(left,right)>0)
    return std::max(left, right) + root->val;
    else return root->val;
}
    
    int maxPathSum(TreeNode* root) {
        
    int sum = INT_MIN;
    traverse(root, sum);
    
    return sum;
    }
};