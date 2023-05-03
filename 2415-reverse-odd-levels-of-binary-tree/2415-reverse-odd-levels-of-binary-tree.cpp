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
void BFS(TreeNode *root, std::vector<std::vector<int>> &store)
{
    if (root == NULL)
        return;

    std::queue<TreeNode *> inox;
    inox.push(root);

    for (int i = 0; inox.size(); i++)
    {
        int size = inox.size();
        std::vector<int> temp;

        for (int i = 0; i < size; i++)
        {
            TreeNode *atom = inox.front();

            if (atom->left != NULL)
                inox.push(atom->left);
            if (atom->right != NULL)
                inox.push(atom->right);

            temp.push_back(atom->val);
            inox.pop();
        }

        if (i & 1)
            reverse(temp.begin(), temp.end());

        store.push_back(temp);
    }
}
    
void traverse(TreeNode *&root, std::vector<std::vector<int>> &store, int i, std::map<int, int> &inox)
{
    if (root == NULL)
        return;

    if (i & 1)
    {
        inox[i]++;
        root->val = store[i][inox[i] - 1];
    }

    traverse(root->left, store, i + 1, inox);
    traverse(root->right, store, i + 1, inox);
}

    
    TreeNode* reverseOddLevels(TreeNode* root) {
        
    std::vector<std::vector<int>> store;
    std::map<int, int> inox;
        
    BFS(root, store);
    traverse(root, store, 0, inox);
    
    return root;
        
    }
};