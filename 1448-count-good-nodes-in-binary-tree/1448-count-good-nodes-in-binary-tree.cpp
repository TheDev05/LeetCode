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
void traverse(TreeNode *root, std::map<int, int> &data, int &count)
{
    if (root == NULL)
        return;

    if (data.size() && data.rbegin()->first <= root->val)
        count++;

    data[root->val]++;

    traverse(root->left, data, count);
    traverse(root->right, data, count);

    data[root->val]--;
    if (data[root->val] == 0)
        data.erase(root->val);

    return;
}
    
    int goodNodes(TreeNode* root) {
    std::map<int, int> data;

    int count = 1;
    traverse(root, data, count);
    
    return count;
    }
};