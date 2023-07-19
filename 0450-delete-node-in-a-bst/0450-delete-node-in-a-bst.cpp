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
TreeNode *traverse(TreeNode *temp)
{
    if (temp->left == NULL && temp->right == NULL)
        return NULL;

    if (temp->left && temp->right)
    {
        TreeNode *inox = temp->right;
        while (inox->left)
            inox = inox->left;

        inox->left = temp->left;
        return temp->right;
    }
    else if (temp->left)
        return temp->left;
    else
        return temp->right;
}

    
    TreeNode* deleteNode(TreeNode* root, int key) {
    
    if(root == NULL) return {};
    if(root -> val == key) return traverse(root);
    
    TreeNode *temp = root;
    TreeNode *parent = NULL;

    while (temp)
    {
        if (temp->val == key)
        {
            TreeNode *inox = traverse(temp);

            if (parent->left && parent->left->val == key)
                parent->left = inox;
            else
                parent->right = inox;

            break;
        }

        parent = temp;

        if (temp->val > key)
            temp = temp->left;
        else
            temp = temp->right;
    } 
        
    return root;
    }
};