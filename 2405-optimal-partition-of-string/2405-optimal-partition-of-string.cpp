class Solution {
public:
    int partitionString(string text) {
        
        std::set<char>store;
        
        int count=1;
        for(int i=0; i<text.size();i++)
        {
            if(store.count(text[i])==false)
            {
                store.insert(text[i]);
            }else 
            {
                count++;
                
                store.clear();
                store.insert(text[i]);
            }
        }
        
        return count;
        
    }
    
};