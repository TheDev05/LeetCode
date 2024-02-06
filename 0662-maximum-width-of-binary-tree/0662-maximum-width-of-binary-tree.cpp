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

    std::queue<TreeNode *> inox;
    std::map<TreeNode *, long long> temp;

    inox.push(root);
    temp[root] = 1;

    long long max = 0;
    while (inox.size())
    {
        int size = inox.size();
        long long min = -1, left = -1, right = -1;

        for (int i = 0; i < size; i++)
        {
            auto it = inox.front();
            inox.pop();

            if (it->left)
            {
                inox.push(it->left);
                if (min == -1)
                min = temp[it] * 2;

                temp[it->left] = (temp[it] * 2) - min;
            }

            if (it->right)
            {
                inox.push(it->right);
                if (min == -1)
                min = (temp[it] * 2) + 1;

                temp[it->right] = ((temp[it] * 2) + 1) - min;
            }

            if (left == -1)
                left = temp[it];
            right = temp[it];
        }

        max = std::max(max, (right - left) + 1);
    }

    return max;
}
    
    int widthOfBinaryTree(TreeNode* root) {
    return traverse(root); 
        
    }
};
