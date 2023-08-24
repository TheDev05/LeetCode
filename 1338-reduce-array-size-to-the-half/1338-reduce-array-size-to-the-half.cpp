class Solution {
public:
    int minSetSize(vector<int>& num) {
        
        int n=num.size();
        
        std::map<int,int>data;
        for(auto i: num) data[i]++;
        
        std::priority_queue<std::pair<int,int>>inox;
        for(auto i: data) inox.push({i.second, i.first});
        
        int count = 0, res = 0;
        while(inox.size())
        {
            if(res >= n/2)break;
            
            auto it=inox.top(); inox.pop();
            count++; res += it.first;
        }
        
        return count;
    }
};