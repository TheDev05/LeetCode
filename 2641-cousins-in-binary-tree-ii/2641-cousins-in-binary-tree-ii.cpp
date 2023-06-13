
class Solution {
public:
void dfs(TreeNode *root, std::map<int, int> &data, int index)
{
    if (root == NULL)
        return;

    data[index] += root->val;

    dfs(root->left, data, index + 1);
    dfs(root->right, data, index + 1);

    return;
}

    TreeNode* replaceValueInTree(TreeNode* root) {

    std::map<int, int> data;
    dfs(root, data, 0);

    int index = 0;
    std::queue<TreeNode *> inox;

    inox.push(root);
    while (inox.size())
    {
        int size = inox.size();
        for (int i = 0; i < size; i++)
        {
            TreeNode *temp = inox.front();
            inox.pop();

            int sum = 0;
            if (temp->left != NULL)
            {
                inox.push(temp->left);
                sum += temp->left->val;
            }

            if (temp->right != NULL)
            {
                inox.push(temp->right);
                sum += temp->right->val;
            }

            if (temp->left != NULL)
                temp->left->val = data[index + 1] - sum;
            if (temp->right != NULL)
                temp->right->val = data[index + 1] - sum;
        }

        index++;
    }

    root->val = 0;
    return root;   

    }
};