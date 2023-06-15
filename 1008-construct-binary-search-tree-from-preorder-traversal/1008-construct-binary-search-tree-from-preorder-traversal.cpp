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
TreeNode *traverse(std::vector<int> &preorder, std::vector<int> &inorder, std::map<int, int> &data, int left, int right, int index)
{
    if (right < left || index >= preorder.size())
        return NULL;

    int pos = data[preorder[index]];
    TreeNode *root = new TreeNode(preorder[index]);

    root->left = traverse(preorder, inorder, data, left, pos - 1, index + 1);
    root->right = traverse(preorder, inorder, data, pos + 1, right, index + (pos - left) + 1);

    return root;
}
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        
    std::vector<int>inorder;
        
    inorder = preorder;
    sort(inorder.begin(), inorder.end());

    std::map<int, int> data;
    for (int i = 0; i < inorder.size(); i++)
    {
        data[inorder[i]] = i;
    }

    return traverse(preorder, inorder, data, 0, inorder.size() - 1, 0);        
    }
};