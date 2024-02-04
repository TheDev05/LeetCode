class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& num) {
        
    std::map<int, std::set<int>> idx;
    for (int i = 0; i < num.size(); i++)
        idx[num[i]].insert(i);

    std::vector<int> res;
    for (int i = 0; i < num.size(); i++)
    {
        int temp = INT_MAX;
        auto locate = idx.lower_bound(num[i]);

        for (auto ip = ++locate; ip != idx.end(); ip++)
        {
            if (auto it = ip->second.lower_bound(i); it != ip->second.end())
                temp = std::min(temp, *it - i);
        }

        if (temp == INT_MAX)
            temp = 0;

        res.push_back(temp);
    } 
        
    return res;
        
    }
};