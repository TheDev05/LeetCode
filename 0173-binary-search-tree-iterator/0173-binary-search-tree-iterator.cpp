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
void pushLeft(TreeNode *root, std::stack<TreeNode *> &st)
{
    if (root == NULL)
        return;

    while (root)
    {
        st.push(root);
        root = root->left;
    }
}

class BSTIterator
{
    std::stack<TreeNode *> st;

public:
    BSTIterator(TreeNode *root)
    {
        pushLeft(root, st);
    }

    int next()
    {
        TreeNode *temp = st.top();
        st.pop();

        if (temp->right)
            pushLeft(temp->right, st);

        return temp->val;
    }

    bool hasNext()
    {
        return st.empty() ? false : true;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */