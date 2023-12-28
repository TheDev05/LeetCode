/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    
    Node* traverse(Node* node)
    {        
        if(node == NULL) return node;
        
        std::queue<Node*>inox;
        inox.push(node);
        
        std::set<Node*>vis;
        std::map<int, Node*>data;
        
        Node* newNode = new Node(node->val);
        data[node->val] = newNode;
                
        while(inox.size())
        {
            auto it = inox.front(); 
            inox.pop();
            
            vis.insert(it);
              
            std::vector<Node*>temp;
            for(int i=0;i<it->neighbors.size();i++)
            {
                if(vis.count(it->neighbors[i]) == false)
                {
                    inox.push(it->neighbors[i]);
                    vis.insert(it->neighbors[i]);
                
                    Node* newTemp = new Node(it->neighbors[i]->val);
                    data[it->neighbors[i]->val] = newTemp;
                    temp.push_back(newTemp);
                
                 }else
                temp.push_back(data[it->neighbors[i]->val]);
            }
            
            data[it->val]->neighbors=temp;
        }
        
      return data[node->val];  
    }
    
    Node* cloneGraph(Node* node) {
      return traverse(node); 
    }
};