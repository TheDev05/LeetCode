class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& num) {
    sort(begin(num), end(num));

    int min = num[0][0], max = num[0][1];
    std::vector<std::vector<int>> res;

    for (int i = 1; i < num.size(); i++)
    {
        if (min <= num[i][0] && num[i][0] <= max)
            max = std::max(max, num[i][1]);
        else
        {
            res.push_back({min, max});
            min = num[i][0];
            max = num[i][1];
        }
    }

    res.push_back({min, max});
    return res;
        
    }
};