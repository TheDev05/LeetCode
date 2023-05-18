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
int traverse(TreeNode *root, std::map<TreeNode *, int> &store, int toggle)
{
    if (root == NULL)
        return 0;

    if (store.count(root) == false)
    {
        int val1 = 1 + traverse(root->left, store, 0);
        int val2 = 1 + traverse(root->right, store, 1);

        int result = 0;

        if (toggle == -1)
            result = std::max(val1, val2) - 1;
        else if (toggle == 0)
            result = val2;
        else
            result = val1;

        store[root] = result;
    }

    return store[root];
}
    
    int longestZigZag(TreeNode* root) {
        
    TreeNode *inox = NULL;
    std::map<TreeNode *, int> store;
        
    int result = traverse(root, store, -1), max = 0;        
    for(auto i: store) max = std::max(max, i.second);
        
    return max;
        
    }
};