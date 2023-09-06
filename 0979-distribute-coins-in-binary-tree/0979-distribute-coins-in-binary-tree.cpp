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
std::pair<int, int> traverse(TreeNode *root, int &sum)
{
    if (root == NULL)
        return {0, 0};

    auto val1 = traverse(root->left, sum);
    auto val2 = traverse(root->right, sum);

    int need = 1 + val1.second + val2.second, extra = 0;
    int store = val1.first + val2.first + root->val;

    if (store <= need)
        need = need - store;
    else
    {
        extra = store - need;
        need = 0;
    }

    sum += extra + need;
    return {extra, need};
}
    
    int distributeCoins(TreeNode* root) {
    int sum = 0;
    traverse(root, sum);

    return sum;        
    }
};