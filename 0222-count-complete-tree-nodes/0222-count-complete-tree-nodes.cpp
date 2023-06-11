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
    
int left(TreeNode *root)
{
    int left = 0;
    while (root)
    {
        left++;
        root = root->left;
    }

    return left;
}

int right(TreeNode *root)
{
    int right = 0;
    while (root)
    {
        right++;
        root = root->right;
    }

    return right;
}

int traverse(TreeNode *root)
{
    if (root == NULL)
        return 0;

    int leftHeight = left(root), rightHeight = right(root);
    if (leftHeight == rightHeight)
        return (1 << leftHeight) - 1;
    else
        return 1 + traverse(root->left) + traverse(root->right);
}

    int countNodes(TreeNode* root) {        
    return traverse(root);             
    }
};