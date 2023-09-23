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
long long traverse(TreeNode *root, int key)
{
    if (root == NULL)
        return 0;

    std::queue<TreeNode *> inox;
    std::multiset<long long, std::greater<long long>> data;

    inox.push(root);
    while (inox.size())
    {
        long long size = inox.size(), sum = 0;
        for (int i = 0; i < size; i++)
        {
            auto it = inox.front();
            inox.pop();

            if (it->left)
                inox.push(it->left);
            if (it->right)
                inox.push(it->right);

            sum += it->val;
        }

        data.insert(sum);
    }

    if(data.size() < key) return -1;
    return *std::next(data.begin(), key - 1);
}
    
    long long kthLargestLevelSum(TreeNode* root, int key) {
    return traverse(root, key);    
    }
};