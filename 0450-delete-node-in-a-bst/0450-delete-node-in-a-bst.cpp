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
TreeNode *helper(TreeNode *inox)
{
    if (inox->left == NULL)
    {
        inox = inox->right;
    }
    else if (inox->right == NULL)
    {
        inox = inox->left;
    }
    else
    {
        TreeNode *dash = inox->left;
        while (dash->right)
        {
            dash = dash->right;
        }

        if (dash->right == NULL)
            dash->right = inox->right;
        inox = inox->left;
    }

    return inox;
}
    
    TreeNode* deleteNode(TreeNode* root, int key) {
    TreeNode *temp = root;

    if (temp && key == temp->val)
        return helper(temp);

    while (temp)
    {
        if (temp->val < key)
        {
            if (temp->right && temp->right->val == key)
            {
                temp->right = helper(temp->right);
                break;
            }
            else
                temp = temp->right;
        }
        else
        {
            if (temp->left && temp->left->val == key)
            {
                temp->left = helper(temp->left);
                break;
            }
            else
                temp = temp->left;
        }
    }
        
   return root;
    }
};