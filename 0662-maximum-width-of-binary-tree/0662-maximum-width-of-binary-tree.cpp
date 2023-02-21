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
long long traverse(TreeNode *root)
{
    if (root == NULL)
        return 0;

    std::queue<TreeNode *> temp;
    std::map<TreeNode *, long long> data;

    temp.push(root);
    data[root] = 1;

    long long max = 1;
    while (temp.size())
    {
        int size = temp.size();
        max = std::max(max, (data.rbegin()->second - data.begin()->second) + 1);

        int min=data.begin()->second;
        for (int i = 0; i < size; i++)
        {
            TreeNode *local = temp.front();
            temp.pop();

            if (local->left != NULL)
            {
                data[local->left] = 2 * (data[local]-min);
                temp.push(local->left);
            }

            if (local->right != NULL)
            {
                data[local->right] = ((long long)2 * (data[local]-min)) + 1;
                temp.push(local->right);
            }

            data.erase(local);
        }
    }

    return max;
}
    int widthOfBinaryTree(TreeNode* root) {
    return (int)traverse(root);
        
    }
};