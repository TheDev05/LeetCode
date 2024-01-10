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
TreeNode *traverse(TreeNode *root, int key, std::map<TreeNode *, TreeNode *> &data)
{
    if (root == NULL)
        return NULL;

    if (root->left)
        data[root->left] = root;
    if (root->right)
        data[root->right] = root;

    TreeNode *temp = NULL;
    if (key == root->val)
        temp = root;

    TreeNode *left = traverse(root->left, key, data);
    TreeNode *right = traverse(root->right, key, data);

    return (temp ? temp : left ? left
                      : right  ? right
                               : NULL);
}
    
    int amountOfTime(TreeNode* root, int key) {
        
    std::map<TreeNode *, TreeNode *> data;
    data[root] = NULL;
        
    TreeNode *target = traverse(root, key, data);

    std::queue<TreeNode *> inox;
    inox.push(target);
        
    int count = -1;
    while (inox.size())
    {
        count++;
        
        int size = inox.size();
        for (int i = 0; i < size; i++)
        {
            auto it = inox.front();
            inox.pop();
            
            if (data[it] && data.contains(data[it]))
                inox.push(data[it]);

            if (it->left && data.contains(it->left))
                inox.push(it->left);
            if (it->right && data.contains(it->right))
                inox.push(it->right);

            data.erase(it);
        }        
    }
        
    return count;
    }
};