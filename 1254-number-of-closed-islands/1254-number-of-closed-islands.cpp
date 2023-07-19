class Solution {
public:
    int closedIsland(vector<vector<int>>& num) {
    
    int n=num.size(),m=num[0].size();
    std::vector<std::pair<int, int>> store;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (num[i][j] == 0)
                store.push_back({i, j});
        }
    }

    int r[4] = {-1, 0, 1, 0};
    int c[4] = {0, -1, 0, 1};

    std::vector<std::vector<int>> visited(n, std::vector<int>(m, 0));
    std::queue<std::pair<int, int>> inox;

    int count = 0;
    for (int i = 0; i < store.size(); i++)
    {
        int row = store[i].first;
        int col = store[i].second;

        if (visited[row][col] == 0)
        {
            inox.push(store[i]);
            visited[row][col] = 1;

            bool ok = true;
            while (inox.size())
            {
                int nrow = inox.front().first;
                int ncol = inox.front().second;

                inox.pop();
                if (nrow == 0 || nrow == n - 1 || ncol == 0 || ncol == m - 1)
                    ok = false;

                for (int j = 0; j < 4; j++)
                {
                    int trow = nrow + r[j];
                    int tcol = ncol + c[j];

                    if (trow >= 0 && trow < n && tcol >= 0 && tcol < m && visited[trow][tcol] == 0 && num[trow][tcol] == 0)
                    {
                        visited[trow][tcol] = 1;
                        inox.push({trow, tcol});
                    }
                }
            }

            if (ok)
                count++;
        }
    }

    return count;        
    }
};