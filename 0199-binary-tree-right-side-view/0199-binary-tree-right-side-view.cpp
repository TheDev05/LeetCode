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

    std::queue<TreeNode *> temp;
    temp.push(root);

    while (temp.size())
    {
        int size = temp.size();
        int last = 0;

        for (int i = 0; i < size; i++)
        {
            TreeNode *local = temp.front();
            temp.pop();

            if (local->left != NULL)
                temp.push(local->left);
            if (local->right != NULL)
                temp.push(local->right);

            last = local->val;
        }

        num.push_back(last);
    }
}
    vector<int> rightSideView(TreeNode* root) {
    std::vector<int> num;
    traverse(root, num);
    
    return num;
    }
};