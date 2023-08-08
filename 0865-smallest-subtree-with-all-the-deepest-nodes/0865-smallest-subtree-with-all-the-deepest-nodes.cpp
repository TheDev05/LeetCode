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
std::pair<int, TreeNode *> traverse(TreeNode *root, std::set<TreeNode *> &store)
{
    if (root == NULL)
        return {0, NULL};

    if (store.count(root))
        return {1, root};

    auto it1 = traverse(root->left, store);
    auto it2 = traverse(root->right, store);

    if (it1.first == store.size())
        return it1;
    if (it2.first == store.size())
        return it2;

    return {it1.first + it2.first, root};
}

void LastNodes(TreeNode *root, std::set<TreeNode *> &store)
{
    if (root == NULL)
        return;

    std::queue<TreeNode *> inox;
    inox.push(root);

    while (inox.size())
    {
        int size = inox.size();
        store.clear();

        for (int i = 0; i < size; i++)
        {
            auto it = inox.front();
            inox.pop();

            if (it->left)
                inox.push(it->left);
            if (it->right)
                inox.push(it->right);

            store.insert(it);
        }
    }
}
    
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
    std::set<TreeNode *> store;
    LastNodes(root, store);
        
    return traverse(root, store).second;   
    }
};