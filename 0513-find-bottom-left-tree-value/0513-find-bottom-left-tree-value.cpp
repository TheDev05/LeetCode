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
int traverse(TreeNode *root)
{
    if (root == NULL)
        return -1;

    std::queue<TreeNode *> qt;

    qt.push(root);
    int inox = root->val;

    while (qt.size())
    {
        int size = qt.size();
        inox = qt.front()->val;

        for (int i = 0; i < size; i++)
        {
            TreeNode *temp = qt.front();
            qt.pop();

            if (temp->left)
                qt.push(temp->left);
            if (temp->right)
                qt.push(temp->right);
        }
    }

    return inox;
}
    
    int findBottomLeftValue(TreeNode* root) {
    return traverse(root);        
    }
};