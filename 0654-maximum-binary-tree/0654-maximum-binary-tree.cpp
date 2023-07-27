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
TreeNode *traverse(std::vector<int> &num, int left, int right)
{
    int index = -1, max = -1;
    for (int i = left; i <= right; i++)
    {
        if (num[i] > max)
        {
            max = num[i];
            index = i;
        }
    }
    
    if(index == -1 || max == -1) return NULL;

    TreeNode *root = new TreeNode(max);
    root->left = traverse(num, left, index - 1);
    root->right = traverse(num, index + 1, right);

    return root;
}
    
    TreeNode* constructMaximumBinaryTree(vector<int>& num) {
    return traverse(num, 0, num.size() - 1);
        
    }
};