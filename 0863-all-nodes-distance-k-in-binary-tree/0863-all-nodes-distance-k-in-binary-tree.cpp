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
    void traverse(TreeNode *root, std::map<TreeNode *, TreeNode *> &parentNode)
    {
        if (root == NULL)
            return;

        if (root->left)
            parentNode[root->left] = root;
        if (root->right)
            parentNode[root->right] = root;

        traverse(root->left, parentNode);
        traverse(root->right, parentNode);
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        
    std::map<TreeNode *, TreeNode *> parentNode;
    traverse(root, parentNode);
        
    parentNode[root] = NULL;

    std::queue<TreeNode *> test;
    test.push(target);

    std::vector<int> res;
    while (test.size() && k >= 0)
    {
        int size = test.size();
        for (int i = 0; i < size; i++)
        {
            TreeNode *temp = test.front();
            test.pop();

            if (k == 0)
                res.push_back(temp->val);

            if (parentNode.contains(parentNode[temp]) && parentNode[temp])
                test.push(parentNode[temp]);

            if (temp->left && parentNode.contains(temp->left))
                test.push(temp->left);
            if (temp->right && parentNode.contains(temp->right))
                test.push(temp->right);

            parentNode.erase(temp);
        }
        
        k--;
    }
    
    return res;
    }
};