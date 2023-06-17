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

void traverse(TreeNode *root, std::vector<int> &inorder)
{
    if (root == NULL)
        return;

    traverse(root->left, inorder);
    inorder.push_back(root->val);
    traverse(root->right, inorder);

    return;
}

class BSTIterator
{
public:
    int index = -1;
    std::vector<int> inorder;

    BSTIterator(TreeNode *root)
    {
        traverse(root, inorder);
    }

    int next()
    {
        index++;
        return inorder[index];
    }

    bool hasNext()
    { 
        if(index == (inorder.size() - 1) ){
            
            return false;
    }
        return true;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */