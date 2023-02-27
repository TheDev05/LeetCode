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
int traverse(TreeNode *root, int &count, int &sum)
{
    if (root == NULL)
        return 0;
    else
        count++;

    int temp = count;

    int left = traverse(root->left, count, sum);
    int right = traverse(root->right, count, sum);

    int total = left + right + root->val;
    int delta = (count - temp) + 1;

    if (delta != 0 && total / delta == root->val)
        sum++;

    return left + right + root->val;
}
    int averageOfSubtree(TreeNode* root) {
        
    int sum = 0, count = 0;
    traverse(root, count, sum);

    return sum;        
    }
};