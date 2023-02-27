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

// Using DFS
int traverse(TreeNode *root, std::map<int, int> &data, int level)
{
    if (root == NULL)
        return 0;

    data[level] += root->val;

    traverse(root->left, data, level + 1);
    traverse(root->right, data, level + 1);

    return 0;
}
    int deepestLeavesSum(TreeNode* root) {
    std::map<int, int> data;
    traverse(root, data, 0);

    return data.rbegin()->second;
        
    }
};