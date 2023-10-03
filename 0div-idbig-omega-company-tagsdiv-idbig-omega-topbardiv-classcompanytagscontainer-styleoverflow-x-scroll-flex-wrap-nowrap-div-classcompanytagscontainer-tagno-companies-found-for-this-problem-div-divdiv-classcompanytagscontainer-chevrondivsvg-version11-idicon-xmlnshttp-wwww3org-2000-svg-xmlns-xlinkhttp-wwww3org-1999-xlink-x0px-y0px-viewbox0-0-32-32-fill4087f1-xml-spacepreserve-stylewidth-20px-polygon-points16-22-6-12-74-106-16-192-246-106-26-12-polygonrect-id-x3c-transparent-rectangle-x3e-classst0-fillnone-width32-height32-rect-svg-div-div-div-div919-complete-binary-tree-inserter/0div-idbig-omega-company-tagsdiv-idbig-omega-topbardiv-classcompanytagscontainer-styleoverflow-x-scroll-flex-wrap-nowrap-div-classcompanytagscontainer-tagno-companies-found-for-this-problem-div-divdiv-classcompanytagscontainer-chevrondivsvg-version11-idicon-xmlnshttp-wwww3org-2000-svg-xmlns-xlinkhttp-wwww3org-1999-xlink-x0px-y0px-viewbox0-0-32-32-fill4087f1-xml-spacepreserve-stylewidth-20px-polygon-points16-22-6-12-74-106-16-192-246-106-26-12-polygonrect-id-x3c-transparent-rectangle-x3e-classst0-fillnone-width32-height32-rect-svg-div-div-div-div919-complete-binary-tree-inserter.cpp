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
class CBTInserter {
public:
    
    TreeNode *temp;
    CBTInserter(TreeNode* root) {
        temp = root;
    }
    
    int traverse(TreeNode*temp, int val)
    {
        if(temp == NULL) return 0;
        
        std::queue<TreeNode*>inox;
        inox.push(temp);
        
        while(inox.size())
        {
            int size = inox.size();
            for(int i = 0; i < size; i++)
            {
                auto it = inox.front();
                inox.pop();
                
                if(it->left)
                    inox.push(it->left);
                else 
                {
                    it->left = new TreeNode(val);
                    return it->val;
                }
                
                if(it->right)
                    inox.push(it->right);
                else
                {
                    it->right = new TreeNode(val);
                    return it->val;
                }
            }
        }
        
        return 0;
    }
    
    int insert(int val) {
     return traverse(temp, val) ;  
    }
    
    TreeNode* get_root() {
     return temp;   
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(val);
 * TreeNode* param_2 = obj->get_root();
 */