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
    
TreeNode *validate(std::vector<int> &preorder, int &index, long long left, long long right)
{
    if (index >= preorder.size())
        return NULL;

    if (preorder[index] > left && preorder[index] < right)
    {
        TreeNode *root = new TreeNode(preorder[index]);

        index = index + 1;

        root->left = validate(preorder, index, left, root->val);
        root->right = validate(preorder, index, root->val, right);

        return root;
    }
    else
        return NULL;
}
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {

    long long left = LONG_MIN, right = LONG_MAX;
    int index = 0;

    return validate(preorder, index, left, right); 
        
    }
};