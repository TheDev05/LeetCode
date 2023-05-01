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
int traverse(TreeNode *root, std::map<int, int> &data, int count)
{
    if (root == NULL)
        return 0;

    data[count] += root->val;

    traverse(root->left, data, count + 1);
    traverse(root->right, data, count + 1);

    return 0;
}
    
    int deepestLeavesSum(TreeNode* root) {
    std::map<int, int> data;
    traverse(root, data, 1);

    return (data.rbegin()->second);        
    }
};