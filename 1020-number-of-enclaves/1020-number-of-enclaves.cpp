class Solution {
public:
    int numEnclaves(vector<vector<int>>& num) {
        
    int n =num.size(), m = num[0].size();
    std::queue<std::pair<int, int>> test;
        
    std::vector<std::vector<int>> vis(n, std::vector<int>(m, 0));
        
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if ((i == 0 || i == n - 1 || j == 0 || j == m - 1) && num[i][j])
                {test.push({i, j}); vis[i][j]=1;}
        }
    }
    
    int r[4] = {-1, 1, 0, 0};
    int c[4] = {0, 0, -1, 1};
        
    while (test.size())
    {
        int row = test.front().first;
        int col = test.front().second;

        test.pop();

        for (int i = 0; i < 4; i++)
        {
            int trow = row + r[i];
            int tcol = col + c[i];

            if (trow >= 0 && trow < n && tcol >= 0 && tcol < m && num[trow][tcol] && vis[trow][tcol] == 0)
            {
                vis[trow][tcol] = 1;
                test.push({trow, tcol});
            }
        }
    }

    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (vis[i][j] == 0 && num[i][j])
                count++;
        }
    }

    return count;        
    }
};