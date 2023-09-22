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
void traverse(TreeNode *root, std::vector<std::vector<int>> &res, std::vector<int> &temp, int sum)
{
    if (root == NULL)
        return;

    if (root->left == NULL && root->right == NULL && sum - root->val == 0)
      {temp.push_back(root->val); res.push_back(temp); temp.pop_back();}

    temp.push_back(root->val);
    traverse(root->left, res, temp, sum - root->val);
    traverse(root->right, res, temp, sum - root->val);
    temp.pop_back();
}
    vector<vector<int>> pathSum(TreeNode* root, int target) {
        
    std::vector<std::vector<int>> res;
    std::vector<int> temp;

    traverse(root, res, temp, target);
    return res;
    }
};