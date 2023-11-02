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
std::pair<int, int> traverse(TreeNode *root, int &count)
{
    if (root == NULL)
        return {0, 0};

    auto it1 = traverse(root->left, count);
    auto it2 = traverse(root->right, count);

    int sum = it1.first + it2.first + root->val;
    int nodes = it1.second + it2.second + 1;

    int avg = sum / nodes;
    if (avg == root->val)
        count++;

    return {sum, nodes};
}
    
    int averageOfSubtree(TreeNode* root) {
    int count = 0;
    traverse(root, count);

    return count;        
    }
};