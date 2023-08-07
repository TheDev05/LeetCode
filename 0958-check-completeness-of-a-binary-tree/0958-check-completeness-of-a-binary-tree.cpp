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
        return false;

    std::queue<TreeNode *> store;
    store.push(root);

    bool ok = false;
    while (store.size())
    {
        int size = store.size();
        for (int i = 0; i < size; i++)
        {
            TreeNode *temp = store.front();
            store.pop();

            if (temp == NULL)
                ok = true;
            else
            {
                if (ok)
                    return false;

                store.push(temp->left);
                store.push(temp->right);
            }
        }
    }

    return true;
}
    bool isCompleteTree(TreeNode* root) {
    return traverse(root);        
    }
};