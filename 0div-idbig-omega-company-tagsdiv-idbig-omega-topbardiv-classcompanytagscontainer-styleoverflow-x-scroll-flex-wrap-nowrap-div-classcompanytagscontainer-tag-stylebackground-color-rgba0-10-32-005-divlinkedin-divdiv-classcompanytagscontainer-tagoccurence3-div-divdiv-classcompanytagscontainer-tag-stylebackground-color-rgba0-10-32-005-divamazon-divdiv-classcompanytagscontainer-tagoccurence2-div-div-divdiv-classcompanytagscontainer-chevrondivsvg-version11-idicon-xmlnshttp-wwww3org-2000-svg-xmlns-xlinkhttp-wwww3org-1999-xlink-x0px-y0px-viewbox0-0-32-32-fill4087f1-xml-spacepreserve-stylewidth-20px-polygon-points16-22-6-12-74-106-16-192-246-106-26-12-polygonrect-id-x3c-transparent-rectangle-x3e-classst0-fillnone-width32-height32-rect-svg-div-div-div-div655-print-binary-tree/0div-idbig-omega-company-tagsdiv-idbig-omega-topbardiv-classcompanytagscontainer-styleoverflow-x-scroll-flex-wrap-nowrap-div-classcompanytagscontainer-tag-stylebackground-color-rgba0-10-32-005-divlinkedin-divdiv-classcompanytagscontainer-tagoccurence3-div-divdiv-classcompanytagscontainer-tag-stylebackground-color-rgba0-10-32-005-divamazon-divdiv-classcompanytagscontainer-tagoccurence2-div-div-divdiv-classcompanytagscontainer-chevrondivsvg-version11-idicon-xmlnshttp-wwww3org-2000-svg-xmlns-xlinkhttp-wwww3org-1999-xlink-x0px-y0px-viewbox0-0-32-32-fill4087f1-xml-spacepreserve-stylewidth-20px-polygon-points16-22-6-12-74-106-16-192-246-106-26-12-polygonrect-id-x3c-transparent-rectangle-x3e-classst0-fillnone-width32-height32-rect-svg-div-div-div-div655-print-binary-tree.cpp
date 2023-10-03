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
void traverse(TreeNode *root, int level, int &height)
{
    if (root == NULL)
        return;

    height = std::max(level, height);

    traverse(root->left, level + 1, height);
    traverse(root->right, level + 1, height);
}

void dfs(TreeNode *root, std::vector<std::vector<std::string>> &num, int row, int col, int height)
{
    if (root == NULL)
        return;

    num[row][col] = to_string(root->val);

    dfs(root->left, num, row + 1, col - pow(2, height - row - 1), height);
    dfs(root->right, num, row + 1, col + pow(2, height - row - 1), height);
}
    
    vector<vector<string>> printTree(TreeNode* root) {
        
    int height = 0;
    traverse(root, 0, height);

    std::vector<std::vector<std::string>> num(height + 1, std::vector<std::string>(pow(2, height + 1) - 1, ""));
    dfs(root, num, 0, (num[0].size() - 1) / 2, height);
        
    return num;
    }
};