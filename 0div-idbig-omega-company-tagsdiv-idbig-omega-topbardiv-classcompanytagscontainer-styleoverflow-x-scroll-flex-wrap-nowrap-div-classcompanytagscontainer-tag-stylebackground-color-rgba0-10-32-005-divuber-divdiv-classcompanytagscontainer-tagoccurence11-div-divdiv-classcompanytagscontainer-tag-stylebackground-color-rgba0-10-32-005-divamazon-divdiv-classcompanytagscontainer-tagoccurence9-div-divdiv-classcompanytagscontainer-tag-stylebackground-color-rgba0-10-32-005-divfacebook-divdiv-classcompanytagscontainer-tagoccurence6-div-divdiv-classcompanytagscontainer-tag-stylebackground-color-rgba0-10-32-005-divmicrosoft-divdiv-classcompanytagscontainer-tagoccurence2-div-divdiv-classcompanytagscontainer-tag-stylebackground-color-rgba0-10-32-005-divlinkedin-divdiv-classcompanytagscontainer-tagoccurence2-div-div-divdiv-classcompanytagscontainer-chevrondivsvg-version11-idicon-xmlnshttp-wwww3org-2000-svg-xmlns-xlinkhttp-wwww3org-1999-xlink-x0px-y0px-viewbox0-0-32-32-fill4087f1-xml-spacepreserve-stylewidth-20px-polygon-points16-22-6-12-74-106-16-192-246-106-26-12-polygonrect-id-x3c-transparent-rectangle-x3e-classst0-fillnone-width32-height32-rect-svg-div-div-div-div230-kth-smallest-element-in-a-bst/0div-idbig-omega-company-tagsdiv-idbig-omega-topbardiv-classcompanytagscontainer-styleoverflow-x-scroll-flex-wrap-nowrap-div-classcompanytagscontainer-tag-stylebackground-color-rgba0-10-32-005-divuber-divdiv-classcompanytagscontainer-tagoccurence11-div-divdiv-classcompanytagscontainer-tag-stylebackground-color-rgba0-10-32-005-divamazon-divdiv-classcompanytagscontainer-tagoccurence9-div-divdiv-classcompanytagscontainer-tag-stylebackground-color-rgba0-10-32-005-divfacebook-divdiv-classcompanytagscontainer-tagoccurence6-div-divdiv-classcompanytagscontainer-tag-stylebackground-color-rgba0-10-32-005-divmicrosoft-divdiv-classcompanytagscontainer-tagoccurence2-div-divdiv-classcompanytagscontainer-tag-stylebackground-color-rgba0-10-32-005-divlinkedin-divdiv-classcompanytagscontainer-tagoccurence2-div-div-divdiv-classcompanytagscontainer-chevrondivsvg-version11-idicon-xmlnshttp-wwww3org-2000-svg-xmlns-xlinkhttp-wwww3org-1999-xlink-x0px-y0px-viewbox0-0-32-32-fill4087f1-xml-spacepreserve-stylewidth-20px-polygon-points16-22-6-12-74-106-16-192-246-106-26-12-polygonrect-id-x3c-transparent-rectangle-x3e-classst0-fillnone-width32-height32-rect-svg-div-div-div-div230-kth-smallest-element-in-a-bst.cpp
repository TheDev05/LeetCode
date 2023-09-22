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
int traverse(TreeNode *root, int &index)
{
    if (root == NULL)
        return 0;

    if (traverse(root->left, index))
        return 1;

    index = index - 1;

    if (index == 0)
    {
        index = root->val;
        return 1;
    }   
        

    if (traverse(root->right, index))
        return 1;

    return 0;
}
    
    int kthSmallest(TreeNode* root, int index) {
    traverse(root, index);

    return index;        
    }
};