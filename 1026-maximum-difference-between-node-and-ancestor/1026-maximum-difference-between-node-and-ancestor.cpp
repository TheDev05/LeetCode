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
std::pair<int, int> traverse(TreeNode *root, int &max)
{
    if (root == NULL)
        return {INT_MAX, INT_MIN};

    auto left = traverse(root->left, max);
    auto right = traverse(root->right, max);

    int mini = std::min(left.first, right.first);
    if (mini != INT_MAX)
        max = std::max(max, std::abs(mini - root->val));

    int maxi = std::max(left.second, right.second);
    if (maxi != INT_MIN)
        max = std::max(max, std::abs(maxi - root->val));

    return {std::min(mini, root->val), std::max(root->val, maxi)};
}
    
    int maxAncestorDiff(TreeNode* root) {
    int max = 0;
    traverse(root, max);

    return max;        
    }
};