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

    std::queue<TreeNode *> qt;
    qt.push(root);

    while (qt.size())
    {
        int size = qt.size();
        std::vector<int> temp;

        for (int i = 0; i < size; i++)
        {
            TreeNode *inox = qt.front();
            qt.pop();

            if (inox->left)
                qt.push(inox->left);
            if (inox->right)
                qt.push(inox->right);

            temp.push_back(inox->val);
        }

        store.push_back(temp);
    }
}
    
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
    std::vector<std::vector<int>> store, result;
    traverse(root, store);

    for (int i = 0; i < store.size(); i++)
    {
        result.push_back(store[store.size() - 1 - i]);
    }
        
    return result;
        
    }
};