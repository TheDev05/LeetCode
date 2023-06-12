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
TreeNode *traverse(std::vector<int> &in, int inStart, int inLast, std::vector<int> &post, int postStart, int postLast)
{
    if (inStart > inLast || postStart > postLast)
        return NULL;

    int rootIndex = inox[post[postLast]];
    TreeNode *root = new TreeNode(post[postLast]);

    root->left = traverse(in, inStart, rootIndex - 1, post, postStart, postLast - 1 - (inLast - rootIndex));
    root->right = traverse(in, rootIndex + 1, inLast, post, postLast - (inLast - rootIndex), postLast - 1);

    return root;
}
    
    TreeNode* buildTree(vector<int>& in, vector<int>& post) {
    for (int i = 0; i < post.size(); i++)
    {
        inox[in[i]] = i;
    }

    return traverse(in, 0, in.size() - 1, post, 0, post.size() - 1);        
    }
};