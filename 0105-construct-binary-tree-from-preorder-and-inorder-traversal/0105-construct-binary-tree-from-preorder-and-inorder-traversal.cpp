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
TreeNode *traverse(std::vector<int> &pre, int preStart, int preEnd, std::vector<int> &in, int inStart, int inEnd)
{
    if (preEnd < preStart || inEnd < inStart)
        return NULL;

    int rootIndex = inox[pre[preStart]];
    TreeNode *root = new TreeNode(in[rootIndex]);

    root->left = traverse(pre, preStart + 1, preStart + (rootIndex - inStart), in, inStart, rootIndex - 1);
    root->right = traverse(pre, preStart + 1 + (rootIndex - inStart), preEnd, in, rootIndex + 1, inEnd);

    return root;
}

    
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
       
    int n = in.size();
    for (int i = 0; i < in.size(); i++)
    {
        inox[in[i]] = i;
    }

    return traverse(pre, 0, n - 1, in, 0, n - 1);        
    }
};