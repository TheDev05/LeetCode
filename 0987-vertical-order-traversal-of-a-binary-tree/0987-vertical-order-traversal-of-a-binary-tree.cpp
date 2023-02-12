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
int Preorder(TreeNode *root, std::map<int, std::map<int, std::multiset<int>>> &num, int i, int j)
{
    if (root == NULL)
        return 0;

    num[i][j].insert(root->val);
    Preorder(root->left, num, i - 1, j + 1);
    Preorder(root->right, num, i + 1, j + 1);

    return 0;
}

    vector<vector<int>> verticalTraversal(TreeNode* root) {
    std::map<int, std::map<int, std::multiset<int>>> num;
    Preorder(root, num, 0, 0);

    std::vector<std::vector<int>> result;
    for (auto i : num)
    {
        std::vector<int> temp;
        for (auto j : i.second)
        {
            for (auto k : j.second)
                temp.push_back(k);
        }
        result.push_back(temp);
    }
    
    return result;
    }
};