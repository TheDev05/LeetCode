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
int traverse(TreeNode *root)
{
    if (root == NULL)
        return 0;

    std::queue<TreeNode *> temp;
    temp.push(root);

    int sum = 0;
    while (temp.size())
    {
        int size = temp.size();
        for (int i = 0; i < size; i++)
        {
            TreeNode *local = temp.front();
            temp.pop();

            if (local->val % 2 == 0)
            {
                if (local->left != NULL && local->left->left != NULL)
                    sum += local->left->left->val;
                if (local->left != NULL && local->left->right != NULL)
                    sum += local->left->right->val;

                if (local->right != NULL && local->right->left != NULL)
                    sum += local->right->left->val;
                if (local->right != NULL && local->right->right != NULL)
                    sum += local->right->right->val;
            }

            if (local->left != NULL)
                temp.push(local->left);
            if (local->right != NULL)
                temp.push(local->right);
        }
    }

    return sum;
}

    int sumEvenGrandparent(TreeNode* root) {
     return traverse(root);        
    }
};