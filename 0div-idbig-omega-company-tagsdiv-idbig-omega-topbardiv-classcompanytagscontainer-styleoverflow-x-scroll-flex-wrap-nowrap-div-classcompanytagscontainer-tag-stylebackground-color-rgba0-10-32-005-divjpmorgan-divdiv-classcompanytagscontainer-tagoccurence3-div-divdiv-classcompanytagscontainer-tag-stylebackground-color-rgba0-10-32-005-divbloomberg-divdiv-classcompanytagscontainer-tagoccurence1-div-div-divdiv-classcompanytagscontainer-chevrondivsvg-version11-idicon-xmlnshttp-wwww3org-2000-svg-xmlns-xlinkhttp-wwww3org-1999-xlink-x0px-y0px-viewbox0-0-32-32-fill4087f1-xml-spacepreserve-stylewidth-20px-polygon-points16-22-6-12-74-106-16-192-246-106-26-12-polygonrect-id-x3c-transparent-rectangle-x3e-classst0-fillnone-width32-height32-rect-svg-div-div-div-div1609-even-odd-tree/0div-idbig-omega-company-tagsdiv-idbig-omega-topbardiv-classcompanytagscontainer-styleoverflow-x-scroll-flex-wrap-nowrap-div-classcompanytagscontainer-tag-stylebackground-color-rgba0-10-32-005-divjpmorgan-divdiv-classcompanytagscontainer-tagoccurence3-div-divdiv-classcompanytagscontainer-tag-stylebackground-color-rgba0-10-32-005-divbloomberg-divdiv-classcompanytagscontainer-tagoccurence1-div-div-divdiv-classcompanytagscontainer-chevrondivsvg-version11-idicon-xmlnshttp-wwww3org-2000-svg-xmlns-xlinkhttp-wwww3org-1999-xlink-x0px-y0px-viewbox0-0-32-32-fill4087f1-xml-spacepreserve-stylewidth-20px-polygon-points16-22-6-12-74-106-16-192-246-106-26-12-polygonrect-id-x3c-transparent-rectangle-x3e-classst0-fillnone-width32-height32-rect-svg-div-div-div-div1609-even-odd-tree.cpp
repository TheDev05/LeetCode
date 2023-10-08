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
bool traverse(TreeNode *root)
{
    if (root == NULL)
        return true;

    std::queue<TreeNode *> inox;
    inox.push(root);

    int idx = 0;
    while (inox.size())
    {
        int size = inox.size(), prev = 0;
        for (int i = 0; i < size; i++)
        {
            auto it = inox.front();
            inox.pop();

            if (it->left)
                inox.push(it->left);
            if (it->right)
                inox.push(it->right);

            if ((idx & 1) && ((prev && prev <= it->val) || (it->val & 1)))
                return false;
            if (!(idx & 1) && ((prev && prev >= it->val) || !(it->val & 1)))
                return false;

            prev = it->val;
        }

        idx++;
    }

    return true;
}
    
    bool isEvenOddTree(TreeNode* root) {
    return traverse(root);    
    }
};