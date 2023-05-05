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
void traverse(TreeNode *root, int &delta, int &max, int &min)
{
    if (root == NULL)
        return;

    if (max >= 0)
    {
        delta = std::max(delta, abs(max - (root->val)));
        delta = std::max(delta, abs(min - (root->val)));
    }

    int temp1 = max, temp2 = min;
    max = std::max(max, root->val);
    min = std::min(min, root->val);

    traverse(root->left, delta, max, min);
    traverse(root->right, delta, max, min);

    max = temp1;
    min = temp2;

    return;
}
    
    int maxAncestorDiff(TreeNode* root) {
        
    int delta = 0, max = -1, min = INT_MAX;
    traverse(root, delta, max, min);
    
    return delta;
    }
};