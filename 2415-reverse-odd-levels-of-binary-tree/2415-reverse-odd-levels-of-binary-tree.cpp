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
        std::vector<TreeNode *> temp;

        for (int i = 0; i < size; i++)
        {
            TreeNode *atom = inox.front();

            if (atom->left != NULL)
                inox.push(atom->left);
            if (atom->right != NULL)
                inox.push(atom->right);

            temp.push_back(atom);
            inox.pop();
        }

        if (i & 1)
        {
           for(int j=0; j < temp.size()/2; j++)
           {
               TreeNode *alpha = temp[j];
               TreeNode *beta = temp[temp.size()-1-j];
               
               int dot = alpha->val;
               alpha->val = beta->val;
               beta->val = dot;
           }
        }

    }
}
        
    TreeNode* reverseOddLevels(TreeNode* root) {
        
    std::vector<std::vector<int>> store;        
    BFS(root, store);
    
    return root;
        
    }
};