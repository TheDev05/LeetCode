class Solution {
public:
    int numEnclaves(vector<vector<int>>& num) {
    
    std::vector<std::vector<int>> vis(num.size(), std::vector<int>(num[0].size(), 0));

    int r[4] = {0, 0, -1, 1};
    int c[4] = {1, -1, 0, 0};

    int result = 0;
    for (int i = 0; i < num.size(); i++)
    {
        for (int j = 0; j < num[0].size(); j++)
        {
            if (vis[i][j] == 0 && num[i][j])
            {
                std::queue<std::pair<int, int>> store;

                store.push({i, j});
                vis[i][j] = 1;

                bool ok = true;
                int count = 0;

                while (store.size())
                {
                    int row = store.front().first;
                    int col = store.front().second;

                    store.pop();

                    if (row == 0 || col == 0 || row == num.size() - 1 || col == num[0].size() - 1)
                        ok = false;
                    count++;

                    for (int p = 0; p < 4; p++)
                    {
                        int nrow = row + r[p];
                        int ncol = col + c[p];

                        if (nrow >= 0 && ncol >= 0 && nrow < num.size() && ncol < num[0].size() && num[nrow][ncol] && vis[nrow][ncol] == 0)
                        {
                            vis[nrow][ncol] = 1;
                            store.push({nrow, ncol});
                        }
                    }
                }

                if (ok)
                    result += count;
            }
        }
    }

    return result;        
    }
};