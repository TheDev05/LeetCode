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
void traverse(TreeNode *root, int val, int depth)
{
    if (root == NULL)
        return;

    std::queue<TreeNode *> inox;
    inox.push(root);

    int count = 1;
    while (inox.size())
    {
        int size = inox.size();
        for (int i = 0; i < size; i++)
        {
            auto it = inox.front();
            inox.pop();

            TreeNode *temp1 = NULL;
            TreeNode *temp2 = NULL;
            
            if(it->left)
            temp1 = it->left;
            if(it->right)
            temp2 = it->right;

            if (count == depth - 1)
            {
                it->left = new TreeNode(val);
                it->left->left = temp1;

                it->right = new TreeNode(val);
                it->right->right = temp2;
            }

            if (temp1)
                inox.push(temp1);
            if (temp2)
                inox.push(temp2);
        }
        
        count++;
    }
}
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
    
    if (depth == 1)
    {
        TreeNode *temp = new TreeNode(val);
        temp->left = root;
        temp->right = NULL;

        return temp;
    }

    traverse(root, val, depth);
    return root;

    }
};