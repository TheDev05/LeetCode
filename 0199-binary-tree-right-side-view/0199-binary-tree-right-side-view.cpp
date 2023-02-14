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
    
void traverse(TreeNode *root, std::map<int, int> &num, int j)
{
    if (root == NULL)
        return;

    num[j] = root->val;
    traverse(root->left, num, j + 1);
    traverse(root->right, num, j + 1);

    return;
}
    
    vector<int> rightSideView(TreeNode* root) {
    std::map<int, int> num;
    traverse(root, num, 0);

    std::vector<int> result;
    for (auto i : num)
        result.push_back(i.second);
        
    return result;
    
    }
};