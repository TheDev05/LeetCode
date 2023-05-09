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

void traverse(TreeNode *root1, TreeNode *root2, std::vector<int> &store)
{
    if (root1 == NULL && root2 == NULL)
        return;

    std::queue<TreeNode *> num;

   if(root1!=NULL) num.push(root1);
   if(root2!=NULL) num.push(root2);

    while (num.size())
    {
        int size = num.size();
        for (int i = 0; i < size; i++)
        {
            TreeNode *temp = num.front();
            num.pop();

            if (temp->left != NULL)
                num.push(temp->left);
            if (temp->right != NULL)
                num.push(temp->right);

            store.push_back(temp->val);
        }
    }
}
            

    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
    std::vector<int> store;
    traverse(root1, root2, store);

    std::sort(store.begin(), store.end());
    return store;
    }
};