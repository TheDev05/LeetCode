class Solution {
public:
    static bool cmp(std::pair<int, int> a, std::pair<int, int> b)
    {
        return a.first > b.first;
    }
    
    vector<vector<int>> sortTheStudents(vector<vector<int>>& num, int k) {
        
    std::vector<std::pair<int, int>> data;
    for (int i = 0; i < num.size(); i++)
        data.push_back({num[i][k], i});

    sort(data.begin(), data.end(), cmp);

    std::vector<std::vector<int>> res;
    for (int i = 0; i < data.size(); i++)
    {
        std::vector<int> temp;
        for (int j = 0; j < num[0].size(); j++)
            temp.push_back(num[data[i].second][j]);

        res.push_back(temp);
    }
        
    return res;
    }
};