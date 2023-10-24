class CombinationIterator {
public:
    
    std::set<std::string>data;    
    void traverse(std::string text, std::string temp, int index, int key)
    {
        if(temp.size() == key && data.count(temp) == false)
        {
            data.insert(temp);            
            return;
        }
        
        if(index >= text.size()) return;
         
        traverse(text, temp, index+1, key);
        
        temp += text[index];
        traverse(text, temp, index+1, key);
        temp.erase(temp.size() - 1, 1);
        
        return;
    }
    
    CombinationIterator(string characters, int combinationLength) {
        traverse(characters, "", 0, combinationLength);
    }
    
    string next() {
      std::string temp = *data.begin();
      data.erase(temp);
        
      return temp;
    }
    
    bool hasNext() {
        if(data.size()) return true;
        return false;
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */