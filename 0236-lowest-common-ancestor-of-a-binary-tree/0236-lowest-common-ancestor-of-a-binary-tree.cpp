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
TreeNode *traverse(TreeNode *root, TreeNode *left, TreeNode *right)
{
    if (root == NULL)
        return root;

    TreeNode *temp1 = NULL, *temp2 = NULL;
    temp1 = traverse(root->left, left, right);
    temp2 = traverse(root->right, left, right);

    bool ok = false;
    if (root->val == left->val || root->val == right->val)
        ok = true;

    if (temp1 != NULL && temp2 != NULL)
        return root;
    if (ok)
        return root;
    return (temp1!=NULL) ? temp1 : temp2; 
}
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    return traverse(root, p, q);        
    }
};