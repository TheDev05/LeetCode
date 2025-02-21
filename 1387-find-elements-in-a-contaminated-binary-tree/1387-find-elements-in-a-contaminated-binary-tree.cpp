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
class FindElements {
public:
    std::set<int>nodes;
    int traverse(TreeNode* root, int temp)
    {
        if(root == NULL) return 0;
        
        root->val=temp;
        nodes.insert(temp);
        
        traverse(root->left, (temp*2) + 1);
        traverse(root->right, (temp*2) + 2);
        
        return 0;
    }
    
    FindElements(TreeNode* root) {
        traverse(root, 0);
    }
    
    bool find(int target) {
        return (nodes.count(target)) ? 1 : 0;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */