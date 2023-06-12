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
void traverse(TreeNode *root, std::vector<int> &num)
{
    if (root == NULL)
        return;

    std::queue<TreeNode *> inox;
    inox.push(root);

    while (inox.size())
    {
        int size = inox.size(), sum = 0;
        for (int i = 0; i < size; i++)
        {
            TreeNode *temp = inox.front();
            inox.pop();

            if (temp->left != NULL)
                inox.push(temp->left);
            if (temp->right != NULL)
                inox.push(temp->right);

            sum += temp->val;
        }

        num.push_back(sum);
    }
}
    
    int maxLevelSum(TreeNode* root) {
        
    std::vector<int> inox;
    traverse(root, inox);

    int max = INT_MIN, level = 0;
    for (int i = 0; i < inox.size(); i++)
    {
        if (inox[i] > max)
        {
            max = inox[i];
            level = i;
        }
    }

    return level + 1;         
    }
};