class Solution {
public:
    int findMaxFish(vector<vector<int>>& num) {
        
    int n = num.size(), m = num[0].size();
    std::vector<std::vector<int>> vis(n, std::vector<int>(m, 0));

    int r[4] = {0, 0, -1, 1};
    int c[4] = {1, -1, 0, 0};

    int max = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (vis[i][j] == 0 && num[i][j])
            {
                std::queue<std::pair<int, int>> inox;

                inox.push({i, j});
                vis[i][j] = 1;

                int sum = 0;
                while (inox.size())
                {
                    auto it = inox.front();
                    inox.pop();

                    int row = it.first;
                    int col = it.second;

                    sum += num[row][col];

                    for (int k = 0; k < 4; k++)
                    {
                        int trow = row + r[k];
                        int tcol = col + c[k];

                        if (trow >= 0 && trow < n && tcol >= 0 && tcol < m && vis[trow][tcol] == 0 && num[trow][tcol])
                        {
                            vis[trow][tcol] = 1;
                            inox.push({trow, tcol});
                        }
                    }
                }

                max = std::max(max, sum);
            }
        }
    }

    return max;        
    }
};