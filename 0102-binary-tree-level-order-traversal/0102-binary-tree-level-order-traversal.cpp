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
void traverse(TreeNode *root, std::vector<std::vector<int>> &store)
{
    if (root == NULL)
        return;

    std::deque<TreeNode *> inox;
    inox.push_back(root);

    while (inox.size())
    {
        std::vector<int> temp;
        int size = inox.size();

        for (int i = 0; i < size; i++)
        {
            TreeNode *atom = inox.front();

            if (atom->left != NULL)
                inox.push_back(atom->left);
            if (atom->right != NULL)
                inox.push_back(atom->right);

            temp.push_back(atom->val);
            inox.pop_front();
        }

        store.push_back(temp);
    }

    return;
}

    
    vector<vector<int>> levelOrder(TreeNode* root) {
    std::vector<std::vector<int>> store;
    traverse(root, store);
    
    return store;
    }
};