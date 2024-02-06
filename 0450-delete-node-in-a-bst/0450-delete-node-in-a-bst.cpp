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

    void deleteNode(TreeNode *target, TreeNode *parent)
    {
        if (target->left && target->right)
           { TreeNode* temp = target->right;
            while(temp->left)
            temp = temp->left;
            temp->left = target->left;

            if(parent->left == target)
            parent->left = target->right;
            else parent->right=target->right;
            }

        else if (target->left)
            {
                if(parent->left == target)
            parent->left = target->left;
            else parent->right=target->left;
            }
        else if(target->right)
            {
                if(parent->left == target)
            parent->left = target->right;
            else parent->right=target->right;
            }
        else {
            if(parent->left == target)
            parent->left = NULL;
            else parent->right=NULL;
        }
    }
   
    TreeNode* deleteNode(TreeNode* root, int key) {
        
    if(root == NULL) return root;

    if (root->val == key)
    {
        if (root->left && root->right)
        {
            TreeNode* temp = root->right;
            while(temp->left)
            temp = temp->left;

            temp->left = root->left;
            root = root->right;
        }
        else if (root->left)
            root = root->left;
        else if(root->right)
            root = root->right;
        else root = NULL;

        return root;
    }

    TreeNode *temp = root, *parent = NULL;
    while (temp)
    {
        if (key == temp->val)
        {
            deleteNode(temp, parent);
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