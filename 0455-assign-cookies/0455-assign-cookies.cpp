class Solution {
public:
    int findContentChildren(vector<int>& studs, vector<int>& cook) {
        
        if(std::min(cook.size(),studs.size())==0)return 0;
    
        std::map<int,int>data;
        for(auto i: cook)data[i]++;
        
        int count=0;
        std::sort(studs.begin(),studs.end()); 
        
        for(int i=0;i<studs.size();i++)
        {
            auto it=data.lower_bound(studs[i]);          
            if(it!=data.end())
            {
                count++;
                
                data[it->first]--;
                if(data[it->first]==0)data.erase(it->first);
            }
        }
        
        return count;
    }
};