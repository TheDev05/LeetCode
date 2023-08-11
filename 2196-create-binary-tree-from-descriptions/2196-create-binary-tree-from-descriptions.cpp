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
    TreeNode* createBinaryTree(vector<vector<int>>& num) {
     
    int n = num.size();
    std::map<int, TreeNode *> inox;
        
    for (int i = 0; i < num.size(); i++)
    {
        int data = num[i][0];
        int child = num[i][1];
        int dir = num[i][2];

        if (inox.count(data) == false)
        {
            TreeNode *temp = new TreeNode(data);
            inox[data] = temp;
        }

        if (inox.count(child) == false)
        {
            TreeNode *temp = new TreeNode(child);
            inox[child] = temp;
        }

        if (dir)
            inox[data]->left = inox[child];
        else
            inox[data]->right = inox[child];
    }

    int local = 0;
    for (int i = 0; i < n; i++)
        inox.erase(num[i][1]);

    return(inox.begin()->second);
        
    }
};