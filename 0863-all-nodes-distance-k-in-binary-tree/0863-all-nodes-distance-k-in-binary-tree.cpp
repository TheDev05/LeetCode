/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
void traverse(TreeNode *root, std::map<TreeNode *, TreeNode *> &parent)
{
    if (root == NULL)
        return;

    std::queue<TreeNode *> inox;
    inox.push(root);

    std::vector<int> result;
    while (inox.size())
    {
        int size = inox.size();
        for (int i = 0; i < size; i++)
        {
            TreeNode *temp = inox.front();
            inox.pop();

            if (temp->left != NULL)
            {
                parent[temp->left] = temp;
                inox.push(temp->left);
            }

            if (temp->right != NULL)
            {
                parent[temp->right] = temp;
                inox.push(temp->right);
            }
        }
    }
}
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        
    std::vector<int>result;
    if(k == 0)
    {
        result.push_back(target->val);
        return result;
    }
        
    std::map<TreeNode *, TreeNode *> parent;
    traverse(root, parent);

    std::queue<TreeNode *> inox;
    std::set<TreeNode *> skip;

    inox.push(target);
    while (inox.size())
    {
        int size = inox.size();
        for (int i = 0; i < size; i++)
        {
            TreeNode *temp = inox.front();
            inox.pop();

            if (temp->left != NULL && !skip.count(temp->left))
                inox.push(temp->left);
            if (temp->right != NULL && !skip.count(temp->right))
                inox.push(temp->right);
            if (parent.count(temp) && !skip.count(parent[temp]))
                inox.push(parent[temp]);

            skip.insert(temp);
        }

        k--;

        if (k == 0)
            break;
    }

    while (inox.size())
    {
        result.push_back(inox.front()->val);
        inox.pop();
    }
        
    return result;
        
    }
};