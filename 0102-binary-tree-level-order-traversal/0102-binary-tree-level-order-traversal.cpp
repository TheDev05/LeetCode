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
void traverse(TreeNode *root, std::vector<std::vector<int>> &num)
{
    if (root == NULL)
        return;

    std::queue<TreeNode *> inox;
    inox.push(root);

    while (inox.size())
    {
        int size = inox.size();
        std::vector<int> atom;

        for (int i = 0; i < size; i++)
        {
            TreeNode *temp = inox.front();
            inox.pop();

            if (temp->left != NULL)
                inox.push(temp->left);
            if (temp->right != NULL)
                inox.push(temp->right);

            atom.push_back(temp->val);
        }

        num.push_back(atom);
    }
}

    
    vector<vector<int>> levelOrder(TreeNode* root) {
        
    std::vector<std::vector<int>> store;
    traverse(root, store);
    
    return store;
    }
};