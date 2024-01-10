class BrowserHistory {
public:
    
    class Node
    {
        public:
        std::string text;
        Node *next, *prev;
        
        Node(std::string temp)
        {
            this->text = temp;
            this->next = this->prev = NULL;
        }
    };
    
    Node*pointer = NULL;
    
    BrowserHistory(string homepage) {
        pointer = new Node(homepage);
    }
    
    void visit(string url) {
        Node* temp = new Node(url);
        pointer->next = temp;
        temp->prev = pointer;
        pointer = temp;
    }
    
    string back(int steps) {
       while(pointer->prev && steps)
       {  
           pointer = pointer->prev;
           steps--;
       }
        
       return pointer->text;
    }
    
    string forward(int steps) {
       while(pointer->next && steps)
       {  
           pointer = pointer->next;
           steps--;
       }
        
       return pointer->text;  
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */