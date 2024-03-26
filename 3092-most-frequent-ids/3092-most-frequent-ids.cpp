class Solution {
public:
    vector<long long> mostFrequentIDs(vector<int>& num, vector<int>& freq) {
    
    std::map<long long, long long> data;
    std::set<std::pair<long long, long long>, greater<std::pair<long long, long long>>> idx;

    std::vector<long long> res;
    for (int i = 0; i < num.size(); i++)
    {
        if (freq[i] > 0)
        {
            idx.erase({data[num[i]], num[i]});
            data[num[i]] += freq[i];
            idx.insert({data[num[i]], num[i]});
        }
        else
        {
            idx.erase({data[num[i]], num[i]});
            data[num[i]] += freq[i];
            idx.insert({data[num[i]], num[i]});
        }

        res.push_back(idx.begin()->first);
    }

    return res;
        
    }
};