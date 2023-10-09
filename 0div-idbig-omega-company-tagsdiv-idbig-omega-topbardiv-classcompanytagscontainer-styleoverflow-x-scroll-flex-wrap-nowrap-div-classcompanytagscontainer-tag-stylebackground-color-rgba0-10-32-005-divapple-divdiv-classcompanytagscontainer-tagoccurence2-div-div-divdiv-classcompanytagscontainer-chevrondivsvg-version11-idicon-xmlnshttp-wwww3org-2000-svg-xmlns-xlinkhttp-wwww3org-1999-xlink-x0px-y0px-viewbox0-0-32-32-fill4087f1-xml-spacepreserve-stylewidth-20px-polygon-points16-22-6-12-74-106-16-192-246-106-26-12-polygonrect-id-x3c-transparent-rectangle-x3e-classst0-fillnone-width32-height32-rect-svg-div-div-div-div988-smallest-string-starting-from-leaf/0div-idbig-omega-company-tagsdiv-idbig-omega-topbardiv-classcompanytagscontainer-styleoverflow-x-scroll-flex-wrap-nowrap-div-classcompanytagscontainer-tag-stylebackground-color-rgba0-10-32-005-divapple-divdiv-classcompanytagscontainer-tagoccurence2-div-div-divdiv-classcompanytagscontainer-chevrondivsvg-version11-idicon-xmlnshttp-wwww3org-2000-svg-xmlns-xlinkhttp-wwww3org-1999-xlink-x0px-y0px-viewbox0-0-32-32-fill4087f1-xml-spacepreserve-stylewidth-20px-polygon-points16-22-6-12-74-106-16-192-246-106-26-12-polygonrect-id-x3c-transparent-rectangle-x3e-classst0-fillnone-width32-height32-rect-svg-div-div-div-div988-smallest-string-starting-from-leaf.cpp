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
std::string traverse(TreeNode *root, int prev)
{
    if (root == NULL)
        return "";

    std::string temp;
    temp = (char)('a' + root->val);

    if (root->left == NULL && root->right == NULL)
        return temp;

    std::string left = traverse(root->left, root->val);
    std::string right = traverse(root->right, root->val);

    if (left.empty())
        return right + temp;
    if (right.empty())
        return left + temp;

    left += temp;
    right += temp;

    for (int i = 0; i < std::min(left.size(), right.size()); i++)
    {
        if (left[i] < right[i])
            return left;
        if (right[i] < left[i])
            return right;
    }

    if (left.size() > right.size())
    {
        if (left[right.size()] < (char)('a' + prev))
            return left;
        return right;
    }
    else
    {
        if (right[left.size()] < (char)('a' + prev))
            return right;
        return left;
    }

    return left;
}

    string smallestFromLeaf(TreeNode* root) {
    return traverse(root, 0);
    }
};
