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
void traverse(TreeNode *root, std::vector<int> &num)
{
    if (root == NULL)
        return;

    traverse(root->left, num);
    num.push_back(root->val);
    traverse(root->right, num);

    return;
}
    
    int kthSmallest(TreeNode* root, int index) {
        
    std::vector<int> num;
    traverse(root, num);

    return num[index - 1];        
    }
};