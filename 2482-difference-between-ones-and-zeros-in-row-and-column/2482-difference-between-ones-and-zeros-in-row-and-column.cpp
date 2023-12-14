class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& num) {
    int n = num.size(), m = num[0].size();
        
    std::vector<std::pair<int, int>> row(n, std::pair<int, int>(0, 0)), col(m, std::pair<int, int>(0, 0));
    // zero, one

    for (int i = 0; i < n; i++)
    {
        int zero = 0, one = 0;
        for (auto j : num[i])
            if (j == 0)
                zero++;
            else
                one++;

        row[i] = {zero, one};        
    }

    for (int i = 0; i < m; i++)
    {
        int zero = 0, one = 0;
        for (int j = 0; j < n; j++)
        {
            if (num[j][i] == 0)
                zero++;
            else
                one++;
        }

        col[i] = {zero, one};
    }

    std::vector<std::vector<int>> res(n, std::vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            res[i][j] = (row[i].second + col[j].second) - (col[j].first + row[i].first);
        }
    }  
        
    return res;
    }
};