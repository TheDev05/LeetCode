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
void Levelorder(std::vector<std::vector<int>> &num, TreeNode *root)
{
    if (root == NULL)
        return;
    
    std::queue<TreeNode *> q;
    q.push(root);

    while (q.size())
    {
        std::vector<int> temp;
        int total = q.size();

        for (int i = 0; i < total; i++)
        {
            TreeNode *node = q.front();
            q.pop();

            if (node->left != NULL)
                q.push(node->left);
            if (node->right != NULL)
                q.push(node->right);

            temp.push_back(node->val);
        }

        num.push_back(temp);
    }
}

    vector<vector<int>> levelOrder(TreeNode* root) {
    std::vector<std::vector<int>> num;
    Levelorder(num, root);
        
    return num;
    }
};