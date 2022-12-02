class Solution {
public:
    bool closeStrings(string word1, string word2) {
        map<char,int>left,right;
        map<int,int>data;
        
        set<char>inox1,inox2;
        for(auto &i: word1)
        {
            left[i]++;
            inox1.insert(i);
        }
        
        for(auto &i:word2)
        {
            right[i]++;
            inox2.insert(i);
        }
        
        for(auto &i: right)
        {
            data[i.second]++;
        }
        
        if(inox1!=inox2)return(0);
        
        for(auto &i: left)
        {
            if(data.count(i.second)==false)
            {
                return(0);
                
            }else 
            {
                data[i.second]--;
                if(data[i.second]==0)data.erase(i.second);
            }
        }
        
        return(1);
    }
};