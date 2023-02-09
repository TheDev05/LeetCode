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
void Levelorder(TreeNode *root, std::vector<std::vector<int>> &num)
{
    if (root == NULL)
        return;

    std::queue<TreeNode *> storage;
    storage.push(root);

    int toggle = 0;
    while (storage.size())
    {
        int size = storage.size();
        std::vector<int> temp(size);

        int index = 0;
        if (toggle & 1)
            index = 0;
        else
            index = size - 1;

        for (int i = 0; i < size; i++)
        {
            TreeNode *local = storage.front();
            storage.pop();

            if (local->left != NULL)
                storage.push(local->left);
            if (local->right != NULL)
                storage.push(local->right);

            temp[abs((size - 1) - index)] = local->val;
            index++;
        }

        num.push_back(temp);
        toggle++;
    }
}
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    std::vector<std::vector<int>> num;
    Levelorder(root, num);
    
    return num;
    }
};