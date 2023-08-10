class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& num) {
    int n = num.size(), m = num[0].size();
        
    std::vector<std::vector<int>> result(n, std::vector<int>(m, 0));
    std::queue<std::pair<int, int>> test;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (num[i][j] == 0)
                test.push({i, j});
        }
    }

    int r[4] = {0, 0, -1, 1};
    int c[4] = {-1, 1, 0, 0};

    while (test.size())
    {
        int row = test.front().first;
        int col = test.front().second;

        test.pop();

        for (int i = 0; i < 4; i++)
        {
            int trow = row + r[i];
            int tcol = col + c[i];

            if (trow >= 0 && trow < n && tcol >= 0 && tcol < m && num[trow][tcol] == 1)
            {
                if (result[trow][tcol])
                    result[trow][tcol] = std::min(result[trow][tcol], result[row][col] + 1);
                else
                {
                    result[trow][tcol] = result[row][col] + 1;
                    test.push({trow, tcol});
                }
            }
        }
    }   
        
    return result;       
    }
};