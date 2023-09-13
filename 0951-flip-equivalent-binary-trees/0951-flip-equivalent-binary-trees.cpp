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
bool traverse(TreeNode *root, std::map<int, int> &parent, bool check)
{
    if (root == NULL)
        return false;

    std::queue<TreeNode *> inox;

    inox.push(root);
    if (check == false)
        parent[root->val] = -1;

    while (inox.size())
    {
        int size = inox.size();
        for (int i = 0; i < size; i++)
        {
            auto it = inox.front();
            inox.pop();

            if (it->left)
            {
                if (check == false)
                    parent[it->left->val] = it->val;
                inox.push(it->left);

                if (check && parent[it->left->val] != it->val)
                    return false;
            }

            if (it->right)
            {
                if (check == false)
                    parent[it->right->val] = it->val;
                inox.push(it->right);

                if (check && parent[it->right->val] != it->val)
                    return false;
            }

            if(check)
            {
                if(parent.count(it->val) == false) return false;
                else parent.erase(it->val);
            }
        }
    }
    
    if (check && parent.size())
        return false;
    return true;
}

    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        
    if(root1 == NULL && root2 == NULL) return true;
        
    std::map<int, int> parent;
    traverse(root1, parent, false);

    return traverse(root2, parent, true);        
    }
};