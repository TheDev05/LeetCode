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

void dfs(TreeNode *root, int key, std::queue<TreeNode *> &leaf, std::map<TreeNode *, TreeNode *> &data)
{
    if (root == NULL)
        return;

    if (root->left)
        data[root->left] = root;
    if (root->right)
        data[root->right] = root;
    if (root->left == NULL && root->right == NULL && root->val == key)
        leaf.push(root);

    dfs(root->left, key, leaf, data);
    dfs(root->right, key, leaf, data);
}  

    TreeNode* removeLeafNodes(TreeNode* root, int key) {
    std::map<TreeNode *, TreeNode *> data;
    std::queue<TreeNode *> leaf;
    
    dfs(root, key, leaf, data);

    while (leaf.size())
    {
        TreeNode *local = leaf.front();
        leaf.pop();

        TreeNode *parent = data[local];
        if(data.count(local))
        {
            if ( parent!=NULL && parent->left && parent->left == local)
                parent->left = NULL;
            if (parent!=NULL&&parent->right && parent->right == local)
                  parent->right = NULL;
        }


        if (parent!=NULL && parent->left == NULL && parent->right == NULL && parent->val == key)
            leaf.push(parent);
    }

    if(root->left==NULL && root->right==NULL && root->val==key) return {};
        
    return root;
        
    }
};