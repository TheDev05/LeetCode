class Solution {
public:
    vector<vector<string>> displayTable(vector<vector<string>>& num) {
    
    int n = num.size();
    
    std::map<std::string, std::map<std::string, int>> data;
        
    std::set<std::string> dish;
    std::set<int>table;

    for (int i = 0; i < n; i++)
    {
        std::string t, d;

        t = num[i][1];
        d = num[i][2];

        dish.insert(d);
        table.insert(stoi(t));

        data[t][d]++;
    }

    std::vector<std::vector<std::string>> result;

    std::vector<std::string> temp;
    temp.push_back("Table");

    for (auto i : dish)
        temp.push_back(i);

    result.push_back(temp);

    for (auto i : table)
    {
        std::vector<std::string> temp;
        temp.push_back(to_string(i));
        
        for (auto j : dish)
            temp.push_back(to_string(data[to_string(i)][j]));

        result.push_back(temp);
    }
        
    return result;
    }
};