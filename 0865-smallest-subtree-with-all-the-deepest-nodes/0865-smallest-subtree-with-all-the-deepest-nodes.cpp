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
void traverse(TreeNode *root, std::map<TreeNode *, TreeNode *> &parent, std::queue<TreeNode *> &temp)
{
    if (root == NULL)
        return;

    std::queue<TreeNode *> inox;
    inox.push(root);

    while (inox.size())
    {
        int size = inox.size();
        std::queue<TreeNode *> atom;

        for (int i = 0; i < size; i++)
        {
            TreeNode *dash = inox.front();
            inox.pop();

            if (dash->left)
            {
                parent[dash->left] = dash;
                inox.push(dash->left);
                atom.push(dash->left);
            }

            if (dash->right)
            {
                parent[dash->right] = dash;
                inox.push(dash->right);
                atom.push(dash->right);
            }
        }

        if (atom.size())
            temp = atom;
    }
}

    
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
    std::map<TreeNode *, TreeNode *> parent;
    std::queue<TreeNode *> temp;

    traverse(root, parent, temp);

    while (temp.size())
    {
        int size = temp.size();
        if (size == 1)
        {
            return temp.front();
            break;
        }

        std::set<int> skip;
        for (int i = 0; i < size; i++)
        {
            TreeNode *dash = temp.front();
            temp.pop();

            TreeNode *atom = parent[dash];
            if (skip.count(atom->val) == false)
            {
                temp.push(atom);
                skip.insert(atom->val);
            }
        }
    }
    
    return root;
    }
};