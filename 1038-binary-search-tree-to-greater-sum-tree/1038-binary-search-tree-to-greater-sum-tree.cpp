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
void traverse(TreeNode *root, std::stack<TreeNode *> &st)
{
    while (root)
    {
        st.push(root);
        root = root->right;
    }
}

    TreeNode* bstToGst(TreeNode* root) {
    std::stack<TreeNode *> st;
    traverse(root, st);

    int inox = 0;
    while (st.size())
    {
        TreeNode *local = st.top();
        st.pop();

        local->val += inox;
        inox = local->val;

        if (local->left)
            traverse(local->left, st);
    }

    return root;        
    }
};