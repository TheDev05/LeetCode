class Solution {
    
    static bool cmp(pair<int,string>val1, pair<int,string>val2)    
    {
        if(val1.first==val2.first)
        return (val1.second<val2.second);
        else return (val1.first>val2.first);
    }
    
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        
        map<string,int>temp;
        vector<pair<int,string>>inox;

        for(auto i: words)temp[i]++;
        for(auto i: temp)inox.push_back({i.second,i.first});

        vector<string>res;
        sort(inox.begin(),inox.end(),cmp);

        int count=0;
        for(auto i: inox)
        {
          if(count<k) res.push_back(i.second);
            else break;
            
            count++;
        }
        
        return res;
            
    }
};