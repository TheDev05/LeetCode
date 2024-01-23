class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& num) {
        
    if(num[0][0] || num[num.size()-1][num[0].size()-1])
       return 0;

    for (auto &i : num)
        for (auto &j : i)
            if (j)
                j = -1;

    std::vector<int> first(num[0].size(), 0), second(num[0].size(), 0);
    second[num[0].size() - 1] = 1;

    for (int i = num.size() - 1; i >= 0; i--)
    {
        for (int j = num[0].size() - 1; j >= 0; j--)
        {
            if (num[i][j] == -1)
            {
                first[j] = -1;
                continue;
            }

            long long val1 = 0, val2 = 0;
            if (j + 1 < num[0].size() && num[i][j + 1] != -1)
                val1 = first[j + 1];

            if (second[j] != -1)
                val2 = second[j];

            first[j] = val1 + val2;
        }

        second = first;
    }

    return first[0]; 
        
    }
};