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
TreeNode *traverse(TreeNode *root, std::set<int> &remove, std::queue<TreeNode *> &inox)
{
    if (root == NULL)
        return NULL;

    if (remove.count(root->val))
    {
        if (root->left)
            inox.push(root->left);
        if (root->right)
            inox.push(root->right);

        return NULL;
    }

    TreeNode *left = traverse(root->left, remove, inox);
    TreeNode *right = traverse(root->right, remove, inox);

    TreeNode *temp = root;
    root->left = left;
    root->right = right;

    return root;
}
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& num) {
        
    std::set<int> remove;
    for (auto i : num)
        remove.insert(i);

    std::queue<TreeNode *> inox;
    inox.push(root);

    std::vector<TreeNode *> res;
    while (inox.size())
    {
        auto it = inox.front();
        inox.pop();

        TreeNode* temp = traverse(it, remove, inox);

        if(temp)
        res.push_back(temp);
    }
        
    return res;
    }
};