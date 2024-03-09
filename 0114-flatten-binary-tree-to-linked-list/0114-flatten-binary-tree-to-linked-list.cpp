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
TreeNode *traverse(TreeNode *root)
{
    if (root == NULL)
        return NULL;

    TreeNode *left = traverse(root->left);
    TreeNode *right = traverse(root->right);

    if(left)
    {
        TreeNode*temp = left;
        while(temp->right)
          temp = temp->right;
    
        temp->right = right;
        root->right = left;
    }
    else 
        root->right = right;
        
    root->left = NULL;
    return root;
}
    
    void flatten(TreeNode* root) {
        
    TreeNode*newRoot = traverse(root);   
    while (newRoot)
    {
        std::cout << newRoot->val << " ";
        newRoot = newRoot->right;
    }
        
    }
};