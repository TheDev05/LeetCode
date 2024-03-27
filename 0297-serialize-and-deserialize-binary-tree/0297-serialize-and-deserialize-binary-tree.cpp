/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {

    std::string text = "";

    if (root == NULL)
        return text;

    std::queue<TreeNode *> inox;

    inox.push(root);
    text += to_string(root->val);

    while (inox.size())
    {
        int size = inox.size();
        for (int i = 0; i < size; i++)
        {
            TreeNode *temp = inox.front();
            inox.pop();

            text += ".";
            if (temp->left != NULL)
            {
                inox.push(temp->left);
                text += to_string(temp->left->val);
            }
            else
                text += 'X';

            text += ".";
            if (temp->right != NULL)
            {
                inox.push(temp->right);
                text += to_string(temp->right->val);
            }
            else
                text += 'X';
        }
    }

    // std::cout << text << '\n';
    return text;      
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string text) {

    if(text.size() == 0) return NULL;
    std::string temp;

    stringstream ss(text);
    getline(ss, temp, '.');

    TreeNode *root = new TreeNode(stoi(temp));

    std::queue<TreeNode *> inox;
    inox.push(root);

    while (inox.size())
    {
            TreeNode *snap = inox.front();
            inox.pop();

            getline(ss, temp, '.');
            if (temp != "X")
            {
                snap->left = new TreeNode(stoi(temp));
                inox.push(snap->left);
            }
            else
                snap->left = NULL;

            getline(ss, temp, '.');
            if (temp != "X")
            {
                snap->right = new TreeNode(stoi(temp));
                inox.push(snap->right);
            }
            else
                snap->right = NULL;    
        
    }

    return root;        
    }
};