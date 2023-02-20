/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
int traverse(TreeNode *root, TreeNode* target, std::vector<TreeNode*> &path)
{
    if (root == NULL)
        return false;

    path.push_back(root);
    if (root == target)
        return true;

    if (traverse(root->left, target, path))
        return true;
    if (traverse(root->right, target, path))
        return true;

    path.pop_back();
    return false;
}
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* target1, TreeNode* target2) {
    std::vector<TreeNode*> path1, path2;

    traverse(root, target1, path1);
    traverse(root, target2, path2);

    std::set<TreeNode*> data;
    for (auto i : path1)
        data.insert(i);

    TreeNode* local = NULL;
    for (int i = 0; i < path2.size(); i++)
    {
        if (data.count(path2[i]))
            local = path2[i];
    }
        
    for(auto i: path1) std::cout<<i->val<<'\n';
    std::cout<<'\n';
    for(auto i: path2) std::cout<<i->val<<'\n';

    return local; 
        
    }
};