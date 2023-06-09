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
void traverse(TreeNode *root, std::map<int, int> &parent, std::map<int, int> &left, std::map<int, int> &right)
{
    if (root == NULL)
        return;

    std::queue<TreeNode *> inox;
    inox.push(root);

    parent[root->val] = -1;
    while (inox.size())
    {
        int size = inox.size();
        for (int i = 0; i < size; i++)
        {
            TreeNode *temp = inox.front();
            inox.pop();

            if (temp->left != NULL)
            {
                parent[temp->left->val] = temp->val;
                left[temp->val] = temp->left->val;

                inox.push(temp->left);
            }
            else
                left[temp->val] = -1;

            if (temp->right != NULL)
            {
                parent[temp->right->val] = temp->val;
                right[temp->val] = temp->right->val;

                inox.push(temp->right);
            }
            else
                right[temp->val] = -1;
        }
    }
}

int backtrack(int val, std::vector<int> &result, std::map<int, int> &parent, std::map<int, int> &left, std::map<int, int> &right, std::set<int> &skip, int k)
{
    if (skip.count(val))
        return 0;

    if (val == -1)
        return 0;

    if (k == 0)
    {
        result.push_back(val);
        return 1;
    }

    skip.insert(val);

    int temp1 = backtrack(parent[val], result, parent, left, right, skip, k - 1);
    int temp2 = backtrack(left[val], result, parent, left, right, skip, k - 1);
    int temp3 = backtrack(right[val], result, parent, left, right, skip, k - 1);

    skip.erase(val);
    return temp1 + temp2 + temp3;
}
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
    int temp = target->val;

    std::map<int, int> parent, left, right;
    std::set<int> skip;

    traverse(root, parent, left, right);
        
    std::vector<int> result;
    backtrack(temp, result, parent, left, right, skip, k);
        
    return result;
        
    }
};