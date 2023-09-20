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
void dfs(TreeNode *root, std::vector<int> &num)
{
    if (root == NULL)
        return;

    num.push_back(root->val);

    dfs(root->left, num);
    dfs(root->right, num);
}

TreeNode *traverse(std::vector<int> &num, int left, int right)
{
    if (left > right)
        return NULL;

    int mid = (right + left) / 2;

    TreeNode *temp = new TreeNode(num[mid]);
    temp->left = traverse(num, left, mid - 1);
    temp->right = traverse(num, mid + 1, right);

    return temp;
}

    
    TreeNode* balanceBST(TreeNode* root) {
        
    std::vector<int> num;
    dfs(root, num);

    sort(num.begin(), num.end());
    return traverse(num, 0, num.size() - 1);
    }
};