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
void traverse(TreeNode *root, int max, int &count)
{
    if (root == NULL)
        return;

    if (root->val >= max)
        count++;

    int temp = max;

    traverse(root->left, std::max(max, root->val), count);
    traverse(root->right, std::max(max, root->val), count);

    max = temp;

    return;
}
    
    int goodNodes(TreeNode* root) {
    std::map<int, int> data;

    int count = 0;
    traverse(root, root->val, count);
    
    return count;
    }
};