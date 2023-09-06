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
    Node* cloneGraph(Node* node) {
        
    if(node == NULL) return {};
             
    std::queue<Node*>inox;
    inox.push(node);
        
    std::map<int, Node*>data; 
    data[node->val] = new Node(node->val);

    while(inox.size())
    {
        int size = inox.size();
        std::vector<Node*>temp;
        
        for(int i=0;i<size;i++)
        {
            auto it=inox.front();
            inox.pop();
                        
            for(auto i: it->neighbors)
            {
                if(data.count(i->val) == false)
                {
                    Node* newNode = new Node(i->val);
                    data[newNode->val] = newNode;
                    
                    inox.push(i);
                }
                           
                temp.push_back(data[i->val]);
                
            } 
                        
            if(data[it->val]->neighbors.empty())
            {
                data[it->val]->neighbors = temp;
                temp.clear();
            }      
        }       
    }
        
    return data[1];
        
    }
};