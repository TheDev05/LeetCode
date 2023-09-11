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
    inox.push(root);

    int count = 0;
    while (inox.size())
    {
        int size = inox.size();

        std::vector<int> temp1, temp2;
        for (int i = 0; i < size; i++)
        {
            auto it = inox.front();
            inox.pop();

            if (it->left)
                inox.push(it->left);
            if (it->right)
                inox.push(it->right);

            temp1.push_back(it->val);
            temp2.push_back(it->val);
        }

        std::sort(temp1.begin(), temp1.end());
        std::map<int,int>data;
        
        for(int i = 0;i<temp2.size();i++) data[temp2[i]] = i;     
        for (int i = 0; i < temp1.size(); i++)
        {
            if (temp1[i] != temp2[i])
            {
                int t1=temp1[i];
                int t2=temp2[i];
                
                count++;
                std::swap(temp2[data[temp1[i]]], temp2[i]);
                        
                data[t2] = data[t1];
                data[t1] = i;
            }
        }
    }

    return count;
}
    int minimumOperations(TreeNode* root) {
    return  traverse(root);        
    }
};