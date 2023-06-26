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
TreeNode *read(TreeNode *root)
{
    if (root->left == NULL && root->right == NULL)
        return NULL;

    if (root->left != NULL && root->right != NULL)
    {
        TreeNode *temp = root->right;
        while (temp->left)
            temp = temp->left;
        
        temp->left = root->left;
        return root->right;
    }
    else if (root->left != NULL)
        return root->left;
    else
        return root->right;
}
 
    TreeNode* deleteNode(TreeNode* root, int key) {
    
    if(root == NULL) return NULL;
    if(root->val == key) return read(root);
        
    TreeNode *temp = root;
    while (temp)
    {
        if (temp->val < key)
        {
            if (temp->right && temp->right->val == key)
            {
                temp->right = read(temp->right);
                break;
            }
            else
                temp = temp->right;
        }
        else
        {
            if (temp->left && temp->left->val == key)
            {
                temp->left = read(temp->left);
                break;
            }
            else
                temp = temp->left;
        }
    }  
        
    return root;
    }
};