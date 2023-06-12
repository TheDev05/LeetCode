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
std::map<int, int> inox;
TreeNode *traverse(std::vector<int> &in, std::vector<int> &pre, int i, int n)
{
    int temp = i;
    int min = INT_MAX, index = -1, val = 0;

    for (i; i < n; i++)
    {
        int j = inox[in[i]];
        
        if (j < min)
        {
            min = j;
            index = i;

            val = in[i];
        }
    }

    if (index == -1)
        return NULL;

    TreeNode *root = new TreeNode(val);
    root->left = traverse(in, pre, temp, index);
    root->right = traverse(in, pre, index + 1, n);

    return root;
}
    TreeNode* buildTree(vector<int>& Preorder, vector<int>& Inorder) {
        
    int n = Preorder.size();
    for (int i = 0; i < Preorder.size(); i++)
    {
        inox[Preorder[i]] = i;
    }
        
    return traverse(Inorder, Preorder, 0, n);
        
    }
};