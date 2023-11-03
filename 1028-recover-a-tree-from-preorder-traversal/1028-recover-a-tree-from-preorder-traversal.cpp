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
TreeNode *traverse(std::vector<int> &num, std::map<int, int> &data, int &index)
{
    TreeNode *root = new TreeNode(num[index]);
    int curr = index;

    bool left = true;
    for (int i = 0; i < 2; i++)
    {
        if (index + 1 < num.size() && data[index + 1] == data[curr] + 1)
        {
            index++;

            TreeNode *temp = traverse(num, data, index);
            if (left)
                root->left = temp, left = false;
            else
                root->right = temp;
        }
        else 
            break;
    }

    return root;
}
    
    TreeNode* recoverFromPreorder(string text) {
        
    std::map<int, int> data;
    std::vector<int> num;

    bool ok = true;
    std::string temp;
    int count = 0, idx = 0;

    for (int i = 0; i < text.size(); i++)
    {
        if (ok && text[i] == '-')
        {
            ok = false;
            data[idx++] = count;
            num.push_back(stoi(temp));
            
            count = 1;
            temp.clear();
        }
        else if (text[i] == '-')
            count++;
        else
            temp += text[i], ok = true;
    }

    if (temp.size())
        data[idx] = count,
        num.push_back(stoi(temp));

    int index = 0;
    return traverse(num, data, index);        
    }
};