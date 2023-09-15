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
void traverse(TreeNode *root, std::map<TreeNode *, TreeNode *> &parent, TreeNode *&init, int start)
{
    if (root == NULL)
        return;

    std::queue<TreeNode *> inox;
    inox.push(root);

    while (inox.size())
    {
        int size = inox.size();
        for (int i = 0; i < size; i++)
        {
            auto it = inox.front();
            inox.pop();

            if (it->left)
            {
                parent[it->left] = it;
                inox.push(it->left);
            }

            if (it->right)
            {
                inox.push(it->right);
                parent[it->right] = it;
            }

            if (it->val == start)
                init = it;
        }
    }
}
    
    int amountOfTime(TreeNode* root, int start) {
        
    std::map<TreeNode *, TreeNode *> parent;
    TreeNode *init = NULL;

    traverse(root, parent, init, start);

    std::queue<TreeNode *> inox;
    std::set<TreeNode *> vis;

    inox.push(init);
    vis.insert(init);

    int count = 0;
    while (inox.size())
    {
        int size = inox.size();
        count++;

        for (int i = 0; i < size; i++)
        {
            auto it = inox.front();
            inox.pop();
            
            if (it->left && vis.count(it->left) == false)
            {
                inox.push(it->left);
                vis.insert(it->left);
            }

            if (it->right && vis.count(it->right) == false)
            {
                inox.push(it->right);
                vis.insert(it->right);
            }

            if (parent[it] && vis.count(parent[it]) == false)
            {
                inox.push(parent[it]);
                vis.insert(parent[it]);
            }
        }
    }

    return count - 1;        
    }
};