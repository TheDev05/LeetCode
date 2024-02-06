class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& num) {
        
    std::map<std::string, std::vector<std::string>> data;
    for (auto i : num)
    {
        std::string temp = i;
        sort(temp.begin(), temp.end());

        data[temp].push_back(i);
    }

    std::vector<std::vector<std::string>> res;
    for (auto i : data)
        res.push_back(i.second);
        
    return res;
        
    }
};