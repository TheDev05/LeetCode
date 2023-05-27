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
std::pair<TreeNode *, int> traverse(TreeNode *root, int height)
{
    if (root->left == NULL && root->right == NULL)
        return {root, height};

    std::pair<TreeNode *, int> temp1 = {NULL, 0}, temp2 = {NULL, 0};

    if (root->left != NULL)
        temp1 = traverse(root->left, height + 1);
    if (root->right != NULL)
        temp2 = traverse(root->right, height + 1);

    if (temp1.first != NULL && temp2.first != NULL && temp1.second == temp2.second)
        return {root, temp1.second};

    if (temp1.second > temp2.second)
        return temp1;
    else if (temp2.second > temp1.second)
        return temp2;

    return {NULL, 0};
}
    
    TreeNode* lcaDeepestLeaves(TreeNode* root) {

    return traverse(root, 1).first;        
        
    }
};