class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& num) {
    
    std::map<std::map<char, int>, std::vector<std::string>> data;
    for (int i = 0; i < num.size(); i++)
    {
        std::map<char, int> temp;
        for (auto j : num[i])
            temp[j]++;

        data[temp].push_back(num[i]);
    }

    std::vector<std::vector<std::string>> res;
    for (auto i : data)
        res.push_back(i.second);

    return res;        
    }
};