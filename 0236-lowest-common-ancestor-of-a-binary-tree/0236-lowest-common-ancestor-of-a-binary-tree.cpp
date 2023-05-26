/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
int traverse(TreeNode *root, TreeNode *val1, TreeNode *val2, TreeNode *&result)
{
    if (root == NULL)
        return 0;

    int temp1 = 0, temp2 = 0, temp3 = 0;

    temp1 = traverse(root->left, val1, val2, result);
    temp2 = traverse(root->right, val1, val2, result);

    if (root->val == val1->val || root->val == val2->val)
        temp3 = 1;

    if (temp1 + temp2 + temp3 == 2)
        result = root;

    if (temp1 || temp2 || temp3)
        return 1;

    return 0;
}
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    TreeNode *result = new TreeNode(0);
    traverse(root, p, q, result);

    return result;        
    }
};