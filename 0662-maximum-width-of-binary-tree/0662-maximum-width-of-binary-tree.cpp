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
void traverse(TreeNode *root, int &max)
{
    if (root == NULL)
        return;

    std::queue<std::pair<TreeNode *, int>> inox;
    inox.push({root, 1});

    while (inox.size())
    {
        long long size = inox.size(), left = -1, right = -1;
        for (int i = 0; i < size; i++)
        {
            TreeNode *temp = inox.front().first;
            long long val = inox.front().second;
            
            inox.pop();

            if (temp->left != NULL)
            {
                if (left == -1)
                    left = val * 2;
                right = val * 2;

                inox.push({temp->left, (val * 2) - left});
            }

            if (temp->right != NULL)
            {
                if (left == -1)
                    left = (val * 2) + 1;
                right = (val * 2) + 1;

                inox.push({temp->right, ((val * 2) + 1) - left});
            }
        }

        max = std::max((long long)max, abs(left - right) + 1);
    }
}
    
    int widthOfBinaryTree(TreeNode* root) {
    int max = 1;

    traverse(root, max);
    return max;        
    }
};