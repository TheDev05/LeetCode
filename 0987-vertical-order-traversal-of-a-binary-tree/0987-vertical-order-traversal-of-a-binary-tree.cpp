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
void Level(TreeNode *root, std::map<int, std::map<int, std::multiset<int>>> &num)
{
    if (root == NULL)
        return;

    std::queue<std::pair<TreeNode *, std::pair<int, int>>> temp;
    temp.push({root, {0, 0}});

    while (temp.size())
    {
        int size = temp.size();
        for (int i = 0; i < size; i++)
        {
            auto inox = temp.front();
            temp.pop();

            if (inox.first->left != NULL)
                temp.push({inox.first->left, {inox.second.first - 1, inox.second.second + 1}});

            if (inox.first->right != NULL)
                temp.push({inox.first->right, {inox.second.first + 1, inox.second.second + 1}});

            num[inox.second.first][inox.second.second].insert(inox.first->val);
        }
    }
}

    vector<vector<int>> verticalTraversal(TreeNode* root) {
    std::map<int, std::map<int, std::multiset<int>>> num;
    Level(root, num);

    std::vector<std::vector<int>> result;
    for (auto i : num)
    {
        std::vector<int> temp;
        for (auto j : i.second)
            temp.insert(temp.end(), j.second.begin(), j.second.end());
        result.push_back(temp);
    }
        
    return result;
    }
};