class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& num) {
        
        std::vector<int>res;
        std::map<int, std::vector<int>>data;
        
        for(int i=0;i<num.size();i++)
        {
            data[num[i][0]].push_back(num[i][1]);
            data[num[i][1]].push_back(num[i][0]);
        }
        
        int index = 1;
        for(auto i: data) if(i.second.size() == 1)
            index = i.first;
        
        while(1)
        {
            res.push_back(index);
            for(auto i: data[index])
            {
                if(data.count(i))
                {
                    data.erase(index), index = i;
                    break;
                }
            }
            
            if(index == res.back())
                break;
        }
        
        return res;
    }
};
