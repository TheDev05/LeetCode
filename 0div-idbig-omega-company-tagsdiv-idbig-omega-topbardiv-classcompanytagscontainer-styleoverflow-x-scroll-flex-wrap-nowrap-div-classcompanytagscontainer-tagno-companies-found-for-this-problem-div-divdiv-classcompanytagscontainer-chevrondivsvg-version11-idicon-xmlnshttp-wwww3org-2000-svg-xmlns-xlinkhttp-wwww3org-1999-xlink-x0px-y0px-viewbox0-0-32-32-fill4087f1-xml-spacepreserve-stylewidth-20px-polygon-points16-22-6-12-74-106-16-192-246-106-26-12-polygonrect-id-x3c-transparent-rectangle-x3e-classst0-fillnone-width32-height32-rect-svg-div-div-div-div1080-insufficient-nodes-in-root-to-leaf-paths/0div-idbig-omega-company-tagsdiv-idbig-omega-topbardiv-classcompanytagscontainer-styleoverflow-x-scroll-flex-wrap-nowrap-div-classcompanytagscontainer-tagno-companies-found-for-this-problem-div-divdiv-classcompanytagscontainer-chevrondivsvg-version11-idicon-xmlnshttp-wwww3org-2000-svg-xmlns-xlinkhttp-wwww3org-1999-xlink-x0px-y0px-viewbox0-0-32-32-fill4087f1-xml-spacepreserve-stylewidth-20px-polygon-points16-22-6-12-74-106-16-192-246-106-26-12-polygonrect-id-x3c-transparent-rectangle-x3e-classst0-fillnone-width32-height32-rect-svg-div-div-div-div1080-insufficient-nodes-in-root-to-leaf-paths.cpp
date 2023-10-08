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
int traverse(TreeNode *root, int sum, int k)
{
    if (root == NULL)
        return 1;
    
    if (root->left == NULL && root->right == NULL)
       if(sum + root->val < k) return 1;
       else return 0;
       
    int val1 = 0, val2 = 0;
    val1 = traverse(root->left, sum + root->val, k);
    val2 = traverse(root->right, sum + root->val, k);

    if (val1)
        root->left = NULL;
    if (val2)
        root->right = NULL;

    return std::min(val1, val2);
}
    
    TreeNode* sufficientSubset(TreeNode* root, int k) {
        
    int val = traverse(root, 0, k); 
    if(val) return {};
    
    return root;
        
    }
};